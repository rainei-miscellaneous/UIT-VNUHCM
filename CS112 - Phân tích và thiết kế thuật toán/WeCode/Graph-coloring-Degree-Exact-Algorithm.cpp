#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n' << '\n' << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)


// Nếu có đường đi -> màu bắt buộc phải khác -> Đệ quy thằng từ cur -> next sẽ phải cho màu khác

void backtrack(int curNode, int v, vector<vector<pair<int, int>>> adj, vector<int> colorUsed, vector<int>& ans, vector<int>& sol, int& maxNum) {
    // Nếu đã tô đủ v đỉnh
    // sol: final ans
    // ans: temp ans

    // if(found) return;

    if(curNode == v) {
        int maxElement = *max_element(all(colorUsed));
        if(maxElement < maxNum) {
            maxNum = maxElement;
            sol = ans;
        }
        return;
    }

    unordered_set<int> usedColorByNeightbor;
    for(const auto& next : adj[curNode])
        usedColorByNeightbor.insert(colorUsed[next.first]);

    // Nếu đồ thị đầy đủ, cần tối đa v màu (0 -> v-1) để có thể tô mà không 2 đỉnh nào chung mà
    
    for(int num = 0; num < v; num++) { // Với đỉnh hiện tại, thử mọi màu khả thi
        if(num > maxNum) return;
        bool flag = 0;
        // Duyệt các node liền kề của node hiện tại, nếu các node liền kề đã dùng các màu thì nó không được dùng màu đó
        if(usedColorByNeightbor.find(num) != usedColorByNeightbor.end()) { // Nếu màu hiện tại đã được dùng bởi lân cận 
            flag = 1;
            continue; // Sang màu khác
        }

        if(num == v - 1 && !flag) return; // thằng hiện tại không thể tô màu trong phạm vi 0 -> v-1, cần tô lại trước đó
        
        colorUsed[curNode] = num; // màu của đỉnh hiện tại
        ans.push_back(num);
        backtrack(curNode + 1, v, adj, colorUsed, ans, sol, maxNum);
        colorUsed[curNode] = -1; // chưa tô nên màu = -1
        ans.pop_back();
    }
}

void solve() {
    
    int v, e;
    cin >> v >> e; 
    
    vector<string> vertex(v);
    map<string, int> mp;

    for(int i = 0; i < v; i++) {
        cin >> vertex[i];
        mp[vertex[i]] = i;
    } 

    vector<vector<pair<int, int>>> adj(v);
    for(int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        adj[mp[u]].pb({mp[v], 1});
        adj[mp[v]].pb({mp[u], 1});
    }
    
    vector<int> colorUsed(v, -1);
    vector<int> ans, sol;
    int maxNum = INT_MAX;
    
    backtrack(0, v, adj, colorUsed, ans, sol, maxNum);
    EACH(u, sol)
        cout << u << ' ';
}

int main() {
    // faster;
    solve();
    return 0;
}
