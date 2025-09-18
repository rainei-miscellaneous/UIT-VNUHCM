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
    int v, e;
    cin >> v >> e;

    // <name, <index, degree>>
    vector<pair<string, pair<int, int>>> vertices(v);
    map<string, int> mappingIndex;

    // đọc tên đỉnh
    for (int i = 0; i < v; i++) {
        string name; 
        cin >> name;
        mappingIndex[name] = i;
        vertices[i] = {name, {i, 0}};
    }

    // xây dựng đồ thị
    map<string, set<string>> adj;
    for (int i = 0; i < e; i++) {
        string c1, c2;
        cin >> c1 >> c2;
        adj[c1].insert(c2);
        adj[c2].insert(c1);
    }

    // Processing
    vector<int> colors(v, -1);
    set<int> Colors;
    for(int i = 0; i < v; i++) {
        string curNode = vertices[i].first;
        if(colors[i] == -1) {
            set<int> usedColors;
            // Tìm các màu đã dùng của các đỉnh lân cận
            for(const auto& adjs : adj[curNode]) {
                int idx = mappingIndex[adjs];
                if(colors[idx] != -1) {
                    usedColors.insert(colors[idx]);
                }
            }
            
            if(usedColors.size() == Colors.size()) {
                colors[i] = *Colors.end() + 1;
            } else {
                colors[i] = findSmallestUnusedColor(usedColors, Colors);
            }

            Colors.insert(colors[i]);
        } else {
            continue;
        }
    }

    for(const auto& i : colors)
        cout << i-1 << ' ';
}

int main() {
    faster;
    solve();
    return 0;
}
