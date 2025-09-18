#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

const int MOD = 1e9 + 7;

void solve() {
    int s;
    cin >> s;

    vector<vector<int>> dp(s+1, vector<int>(7, 0));

    // dp[i][j] số cách đạt tổng i với mặt hiện tại là j

    for(int i = 1; i <= 6 && i <= s; i++) {
        dp[i][i] = 1;
    }

    for(int i = 2; i <= s; i++) {
        for(int k = 1; k <= 6; k++) {
            if (i - k >= 1) {
                for(int j = 1; j <= 6; j++) {
                    dp[i][k] += dp[i-k][j];
                    dp[i][k] %= MOD;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= 6; i++) {
        ans = (ans + dp[s][i]) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    faster;
    solve();
    return 0;
}
