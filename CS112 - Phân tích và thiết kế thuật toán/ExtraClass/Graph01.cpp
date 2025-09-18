/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -

void inputGraph(vector<vector<int>>& G, int v, int e) {
    G = vector<vector<int>> (v, vector<int>(v, 0)); 
    for(int i = 0; i < e; i ++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = 1;
    }
}

void process(const vector<vector<int>> G, int v, int n) {
    for(int num = 0; num < n; num++) {
        int c;
        cin >> c;
        if (c & 1) {
            int u, i;
            cin >> u >> i;
            u--, i--;
            bool flag = (G[u][i]);
            if(flag) 
                cout << "TRUE" << '\n';
            else
                cout << "FALSE" << '\n';
        } else {
            int u;
            cin >> u;
            u--;
            bool flag = 0;
            for(int i = 0; i < v; i++) {
                // if (i == u-1) continue;
                if(G[u][i]) {   
                    flag = 1;
                    cout << i+1 << ' ';
                }
            }
            if (!flag) cout << "NONE";
            cout << '\n';
        }
    }
}

int main()
{

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}
