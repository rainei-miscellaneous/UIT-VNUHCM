#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; string start, end;
    cin >> n >> start;
    map<string, map<string, int>> adj;
    for(int i = 0; i < n; i++) {
        string c1, c2; int cost;
        cin >> c1 >> c2 >> cost;
        adj[c1][c2] = cost;
    }

    vector<string> ans;
    set<string> visited;
    queue<string> q;

    q.push(start);
    visited.insert(start);

    while(q.size()) {
        string curNode = q.front();
        q.pop();
        ans.push_back(curNode);

        // tìm thành phố có cost ít nhất nếu đi từ thành phố hiện tại
        ll MAX = LONG_LONG_MAX;
        for(const auto& neighbor : adj[curNode]) {
            if(visited.find(neighbor.first) == visited.end()) {
                if(neighbor.second < MAX) {
                    MAX = neighbor.second;
                }
            }
        }   

        // bỏ thành phố đó vào hàng chờ
        for(const auto& neighbor : adj[curNode])
            if(MAX == neighbor.second && visited.find(neighbor.first) == visited.end()) {
                q.push(neighbor.first);
                visited.insert(neighbor.first);
            }
    }

    ans.push_back(start);
    for(auto i:ans) 
        cout << i << ' ';
}

int main()
{
    faster;
	solve();
	return 0;
}