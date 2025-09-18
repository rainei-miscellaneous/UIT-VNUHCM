#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int findSmallestUnusedColor(set<int>& usedColors, set<int>& Colors) {
    for (int color : Colors) {
        if (usedColors.find(color) == usedColors.end()) {
            return color;
        }
    }
    return 0;
}

void solve() {
    int v, e, n;
    cin >> v >> e >> n;

    // <name, <color, degree>>
    vector<pair<string, pair<int, int>>> vertices(v);
    map<string, int> mappingIndex;

    // đọc tên đỉnh
    for (int i = 0; i < v; i++) {
        string name; 
        cin >> name;
        mappingIndex[name] = i;
        vertices[i] = {name, {-1, 0}};
    }

    // xây dựng đồ thị
    map<string, set<string>> adj;
    for (int i = 0; i < e; i++) {
        string c1, c2;
        cin >> c1 >> c2;
        adj[c1].insert(c2);
        adj[c2].insert(c1);
    }

    // đọc màu mỗi đỉnh
    for (int i = 0; i < v; i++) {
        cin >> vertices[i].second.first;
        vertices[i].second.second = adj[vertices[i].first].size();
    }

    // tập hợp các màu đã sử dụng
    set<int> colors;
    for (const auto& vertex : vertices) {
        if (vertex.second.first != -1) {
            colors.insert(vertex.second.first);
        }
    }

    // xử lý từng đỉnh cần xem xét
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        int idx = mappingIndex[c];
        int currentColor = vertices[idx].second.first;
        string curNode = vertices[idx].first;

        if (currentColor != -1) { // nếu đỉnh đã tô màu
            bool isValid = 1;
            for (const auto& adjacent : adj[curNode]) {
                int adjIdx = mappingIndex[adjacent];
                if (vertices[adjIdx].second.first == currentColor) {
                    isValid = 0;
                    break;
                }
            }
            if (isValid) {
                cout << "TRUE" << '\n';
                continue;
            }
        }

        // tìm màu nhỏ nhất có thể chọn được
        set<int> usedColors;
        for (const auto& adjacent : adj[curNode]) {
            int adjIdx = mappingIndex[adjacent];
            if (vertices[adjIdx].second.first != -1) {
                usedColors.insert(vertices[adjIdx].second.first);
            }
        }
        
        // for(auto i : colors)
        //     cout << i << ' ';
        
        if(usedColors.size() == colors.size())  {
            int minColor = 0;
            while (usedColors.find(minColor) != usedColors.end() || (currentColor == minColor && usedColors.find(minColor) != usedColors.end())) {
                minColor++;
            }
            cout << minColor << '\n';
        } else {
            cout << findSmallestUnusedColor(usedColors, colors) << '\n';
        }
    }
}

int main() {
    faster;
    solve();
    return 0;
}
