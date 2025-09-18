#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n' << '\n' << '\n';

struct Compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second < b.second; // distance bằng nhau, ưu tiên số thứ tự lớn hơn
        }
        return a.first > b.first; // distance nhỏ hơn
    }
};

void solve() {
    int v, n;
    cin >> v >> n;

    // spacing;
    vector<string> vertices(v);
    map<string, int> mp;

    for (int i = 0; i < v; i++) {
        cin >> vertices[i];
        mp[vertices[i]] = i;
    }

    vector<vector<int>> adj(v, vector<int>(v));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        string s, e;
        cin >> s >> e;
        
        vector<int> dis(v, INT_MAX); // Lưu khoảng cách từ start -> curNode
        dis[mp[s]] = 0; // dis(s, s) = 0

        
        vector<bool> visited(v, 0);
        vector<int> parent(v, -1);
        using T = pair<int,int>;
        priority_queue<T, vector<T>, Compare> pq;
        int time = 0;
        
        pq.push({dis[mp[s]], mp[s]});

        int nodeExpanded = 0;
        
        while (!pq.empty()) {
            int curNode = pq.top().second;
            pq.pop();
            if (visited[curNode]) continue;
            visited[curNode] = 1;
            nodeExpanded++;
            if(vertices[curNode] == e) break;

            for (int j = 0; j < v; j++) {
                if (adj[curNode][j] && !visited[j]) {
                    // cout << vertices[j] << ' ';
                    int weight = adj[curNode][j];
                    if (dis[curNode] + weight < dis[j]) {
                        dis[j] = dis[curNode] + weight;
                        parent[j] = curNode;
                        pq.push({dis[j], j});
                    }
                }
            }
        }

        vector<string> path;
        for (int at = mp[e]; at != -1; at = parent[at]) {
            path.pb(vertices[at]);
        }
        reverse(path.begin(), path.end());

        if(dis[mp[e]] == INT_MAX) {
            cout << "-unreachable-" << '\n';
            cout << nodeExpanded << ' ' << 0 << '\n';
        } else {
            for (const string &node : path) {
                cout << node << ' ';
            }
            cout << '\n';
            cout << nodeExpanded << ' ' << dis[mp[e]] << '\n';
        }
    }
}

int main() {
    faster;
    solve();
    return 0;
}
