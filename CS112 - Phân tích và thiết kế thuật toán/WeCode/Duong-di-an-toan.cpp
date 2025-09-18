#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

const int MOD = 1e9 + 7;
vector<vector<char>> a;
int n;

bool isValid(int i, int j) {
    return (i && j && i <= n && j <= n && a[i][j] == '.');
}

void solve() {
    // input
    cin >> n;
    
    a.resize(n+1, vector<char>(n+1));
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    dp[1][1] = 1;

    for(int j = 2; j <= n; j++) {
        if(isValid(1, j))
            dp[1][j] = dp[1][j-1];
    }

    for(int i = 2; i <= n; i++)  {
        if(isValid(i, 1))
            dp[i][1] = dp[i-1][1];
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            if(isValid(i, j)) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[n][n];
}

int main() {
    // faster;
    solve();
    return 0;
}