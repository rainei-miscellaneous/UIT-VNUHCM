/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph {
    vector<vector<int>> G;
    vector<string> name;
    map<string, int> mp;

public:
    void nhap(int v, int e) {
        G = vector<vector<int>>(v, vector<int>(v, 0));
        name.resize(v);
        for (int i = 0; i < v; i++) {
            string x;
            cin >> x;
            name[i] = x;
            mp[x] = i;
        }

        for (int i = 0; i < e; i++) {
            string u, v;
            cin >> u >> v;  
            G[mp[u]][mp[v]] = 1;
        }
    }

    void myProcess(int n) {
        for(int num = 0; num < n; num++) {
            int c;
            cin >> c;
            if (c & 1) {
                string u, i;
                cin >> u >> i;
                bool flag = (G[mp[u]][mp[i]]);
                if(flag) 
                    cout << "TRUE" << '\n';
                else
                    cout << "FALSE" << '\n';
            } else {
                string u;
                cin >> u;
                bool flag = 0;
                for(int i = 0; i < name.size(); i++) {
                    // if (i == u-1) continue;
                    if(G[mp[u]][mp[name[i]]]) {   
                        flag = 1;
                        cout << name[i] << ' ';
                    }
                }
                if (!flag) cout << "NONE";
                cout << '\n';
            }
        }
    }
};

int main() {
    Graph G;
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    // G.xuat(v, e);
    G.myProcess(n);
    return 0;
}
