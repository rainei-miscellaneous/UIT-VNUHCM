#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> name;
    map<string, set<string>> adj;

    int e, n;
    cin >> e >> n;

    for (int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        adj[v]; // v -> {}
        adj[u].insert(v); // u -> {v}
    }

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if(c&1) {
            string u, v;
            cin >> u >> v;
            if (adj[u].find(v) != adj[u].end())
                cout << "TRUE" << '\n';
            else
                cout << "FALSE" << '\n';
        } else {
            int ans = 0;
            string u;
            cin >> u;
            cout << adj[u].size() << '\n';
        }
    }

}

int main()
{
    faster;
	solve();
	return 0;
}
