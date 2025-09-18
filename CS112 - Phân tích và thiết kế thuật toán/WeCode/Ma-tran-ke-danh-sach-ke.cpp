#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int j = 0; j < n; j++) {
        ll cnt = 0;
        bool flag = 0;
        for(int i = 0; i < n; i++) {
            if(a[i][j]) {
                flag = 1;
                cnt++;
                if(cnt == 1) cout << j + 1 << "->";
                cout << i + 1 << ' ';
            }
        }
        if(flag) cout << '\n';
    }
}

int main()
{
    faster;
	solve();
	return 0;
}