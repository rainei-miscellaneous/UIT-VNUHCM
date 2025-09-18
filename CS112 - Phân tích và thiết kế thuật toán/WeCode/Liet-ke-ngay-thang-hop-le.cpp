#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    map<string, map<string, int>> adj;
    for(int i = 0; i < n; i++) {
        string c1, c2;
        cin >> c1 >> c2;
        adj[c1][c2] = 0;
    }

    for(const auto& pair1 : adj) {
        string curNode = pair1.first;
        for(const auto& pair2 : pair1.second) {
            string nextNode = pair2.first;
            if(adj[curNode].find(nextNode) == adj[curNode].end() || adj[nextNode].find(curNode) == adj[nextNode].end()) {
                cout << "FALSE";
                return;
            }
        }
    }
    cout << "TRUE";
}

int main()
{
    faster;
	solve();
	return 0;
}