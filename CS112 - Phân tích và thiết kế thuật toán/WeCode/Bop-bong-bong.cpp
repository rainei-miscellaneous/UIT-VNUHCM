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
    int n;
    cin >> n;
    vector<int> a(n+2);
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
    }

    a[0] = a[n+1] = 1;

    // dp[i][j] điểm tối đa đạt được khi bóp bong bóng trong range i j
    // đáp án là dp[1][n]
    // tìm k là vị trí pop
    // khi k là thằng cuói cùng trong range i j -> reward = a[k] * a[j+1] * a[i-1]
    // reward khi đó bằng dp[i][k-1] + dp[k+1][j] + a[k] * a[i-1] + a[j+1] 
    // với dp[i][j] = max(dp[i][k-1] + dp[k+1][j] + a[k] * a[i-1] + a[j+1], dp[i][j])

    // bóp tối thiểu 1 bóng và tối đa n - 1 bóng
    for(int len = 1; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for(int k = i; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + a[i-1] * a[k] * a[j+1]);
            }
        }
    }

    cout << dp[1][n];
}

int main() {
    // faster;
    solve();
    return 0;
}