#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

void solve() {
    // input
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // dp[i][j] số phép biến đổi ít nhất để được đoạn s1[1->i] == s2[1->j]

    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    
    cout << dp[n][m];
}

int main() {
    // faster;
    solve();
    return 0;
}