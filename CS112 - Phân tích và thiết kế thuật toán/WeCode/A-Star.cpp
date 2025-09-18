#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n' << '\n' << '\n';
using T = pair<int, int>; // <f, nodeIdx>

struct Compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first) {
            return a.second > b.second; // distance bằng nhau, ưu tiên số thứ tự nhỏ hơn
        }
        return a.first > b.first; // distance nhỏ hơn
    }
};

void updatePQ(priority_queue<T, vector<T>, Compare>& pq, T node) {
    vector<T> temp;
    while(pq.size()) {
        auto current = pq.top();
        pq.pop();
        if(current.second == node.second)
            temp.pb({node.first, node.second});
        else
            temp.pb(current);
    }

    for(const auto& i : temp)
        pq.push(i);
}

void solve() {
    int v, e;
    cin >> v >> e;

    string start, end;
    cin >> start >> end;

    vector<string> vertex(v);
    map<string, int> mp;
    for(int i = 0; i < v; i++) {
        cin >> vertex[i];
        mp[vertex[i]] = i;
    }

    vector<int> heu(v);
    for(int i = 0; i < v; i++) {
        cin >> heu[i];
    }

    vector<vector<int>> adj(v, vector<int>(v));
    for(int i = 0; i < e; i++) {
        string u, v;
        int cost;
        cin >> u >> v >> cost;
        adj[mp[u]][mp[v]] = cost;
    }

    priority_queue<T, vector<T>, Compare> open;
    // set<int> isInOpen;
    // set<int> close;
    vector<bool> isInOpen(v, 0);
    vector<bool> close(v, 0);

    vector<int> parent(v, -1);
    vector<int> g(v, INT_MAX); // khoảng cách từ start -> curNode
    vector<int> f(v, INT_MAX); // độ tốt từ start -> curNode

    g[mp[start]] = 0; // dis(s, s) = 0
    f[mp[start]] = heu[mp[start]]; // f(start) = heuristic(start)
    open.push({f[mp[start]], mp[start]});
    // isInOpen.insert(mp[start]);
    isInOpen[mp[start]] = 1; 

    int nodeExpanded = 0;

    while(!open.empty()) {
        auto current_pair = open.top();
        open.pop();
        int current = current_pair.second;

        // if(close.find(current) != close.end()) continue;
        // close.insert(current);
        if(close[current]) continue;
        close[current] = 1;
        isInOpen[current] = 0;
        nodeExpanded++;

        if(vertex[current] == end) break;

        for(int j = 0; j < v; j++) {
            if(adj[current][j] > 0) {
                
                int tempG = g[current] + adj[current][j];

                if(!isInOpen[j] && !close[j]) {
                    g[j] = tempG;
                    f[j] = g[j] + heu[j];
                    parent[j] = current;
                    open.push({f[j], j});
                    isInOpen[j] = 1;
                } 
                else if(isInOpen[j] && g[j] > tempG) {
                    g[j] = tempG;
                    f[j] = g[j] + heu[j];
                    parent[j] = current;
                    updatePQ(open, {f[j], j});
                }
                else if(close[j] && g[j] > tempG) {
                    // close.erase(j);
                    close[j] = 0;
                    nodeExpanded--;
                    g[j] = tempG;
                    f[j] = g[j] + heu[j];
                    parent[j] = current;
                    open.push({f[j], j});
                    isInOpen[j] = 1;
                }
            }
        }
    }

    spacing;
    if(f[mp[end]] == INT_MAX) {
        cout << "-unreachable-" << '\n';
        cout << nodeExpanded << ' ' << 0 << '\n';
    } else {
        vector<string> path;
        for(int at = mp[end]; at != -1; at = parent[at]) {
            path.pb(vertex[at]);
        }
        reverse(path.begin(), path.end());

        for(const string &node : path) {
            cout << node << ' ';
        }
        cout << '\n';
        cout << nodeExpanded << ' ' << g[mp[end]] << '\n';
    }
}

int main() {
    faster;
    solve();
    return 0;
}
