#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> name;
    map<string, map<string, int>> adj;

    int e, n;   
    cin >> e >> n;

    for (int i = 0; i < e; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        adj[v];
        adj[u][v] = c;
    }

    for (int i = 0; i < n; i++) { 
        string vertex;
        vector<string> path;

        while (cin >> vertex && vertex != ".") {
            path.push_back(vertex);
        }

        long long sum = 0;
        bool flag = 0;
        for (int j = 0; j < path.size() - 1; j++) {
            string u = path[j];
            string v = path[j + 1];
            if (adj[u].find(v) == adj[u].end()) {
                cout << "FALSE" << endl;
                flag = 1;
                break;
            }
            sum += adj[u][v];
        }
        if (!flag) cout << sum << endl;
    }
}

int main()
{
    faster;
	solve();
	return 0;
}