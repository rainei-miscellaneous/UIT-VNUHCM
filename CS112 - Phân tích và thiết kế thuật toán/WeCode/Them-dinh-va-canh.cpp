#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int choice;
    map<string, set<string>> adj;
    while(cin >> choice && choice) {
        if(choice == 1) { // Done
            string c;
            cin >> c;
            
            if(adj.find(c) != adj.end()) {
                cout << "DUP" << '\n';
            } else {
                adj[c];
                cout << "ADD" << '\n';
            }

        } else if(choice == 2) { // Done
            string c1, c2;
            cin >> c1 >> c2;

            if(adj.find(c1) != adj.end() && adj.find(c2) != adj.end()) {
                if(adj[c1].find(c2) != adj[c1].end())  {
                    cout << "DUP2" << '\n';
                } else {
                    adj[c1].insert(c2);
                    cout << "ADD3" << '\n';
                }             
            } else {
                if(!(adj.find(c1) != adj.end()))
                    adj[c1];
                if(!(adj.find(c2) != adj.end()))
                    adj[c2];
                adj[c1].insert(c2);
                cout << "ADD2" << '\n';
            }
            
        } else if(choice == 3) { // Done
            string c1, c2;
            cin >> c1 >> c2;

            if(adj.find(c1) != adj.end() && adj.find(c2) != adj.end() && (adj[c1].find(c2) != adj[c1].end())) {
                cout << "TRUE" << '\n';
            } else {
                cout << "FALSE" << '\n';
            }

        } else if(choice == 4) { // Done
            string c;   
            cin >> c;

            if(adj.find(c) != adj.end()) {
                cout << adj[c].size() << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}

int main()
{
    faster;
	solve();
	return 0;
}