#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

ll minTime = LLONG_MAX;

void minRoadGenerating(int nodeNum, string curNode, string end, vector<string>& ans, vector<string>& sol, unordered_map<string, unordered_map<string, int>>& adj, unordered_set<string>& visited) {
    if(curNode == end && ans.size() > nodeNum) {
        ll totalTime = 0;
        for(int i = 0; i < ans.size() - 1; i++) 
            totalTime += adj[ans[i]][ans[i+1]];
        
        if(totalTime < minTime) {
            minTime = totalTime;
            sol = ans;
        }
        return;
    }
    
    EACH(u, adj[curNode]) {
        if(visited.find(u.first) == visited.end()) {
            visited.insert(u.first);
            ans.pb(u.first);
            minRoadGenerating(nodeNum, u.first, end, ans, sol, adj, visited);
            visited.erase(u.first); 
            ans.pop_back();
        }
    }
}

void solve() {
    int n;
    string start;
    cin >> n >> start;
    
    unordered_map<string, unordered_map<string, int>> adj;
    unordered_set<string> vertex;
    
    for(int i = 0; i < n; i++) {
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        vertex.insert(c1);
        vertex.insert(c2);
        adj[c1][c2] = cost;
    }   

    int nodeNum = vertex.size();
    vector<string> ans = {start};
    vector<string> sol;
    unordered_set<string> visited;
    
    spacing;
    minRoadGenerating(nodeNum, start, start, ans, sol, adj, visited);
    spacing;
    
    EACH(u, sol)
        cout << u << ' ';
}

int main() {
    // faster;
    solve();
    return 0;
}
