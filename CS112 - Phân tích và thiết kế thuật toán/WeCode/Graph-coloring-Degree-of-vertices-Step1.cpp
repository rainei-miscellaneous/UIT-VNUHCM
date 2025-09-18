#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
    int v, e;
    cin >> v >> e;

    vector<string> name;
    map<string, int> vertices;
    for(int i = 0; i < v; i++) {
        string c; cin >> c;
        name.pb(c);
        vertices[c] = 0;
    }
    
    for(int i = 0; i < e; i++) {
        string c1, c2; 
        cin >> c1 >> c2;
        vertices[c1]++;
        vertices[c2]++;
    }

    for(int i = 0; i < name.size(); i++) {
        cout << vertices[name[i]] << ' ';
    }
}

int main()
{
    faster;
	solve();
	return 0;
}