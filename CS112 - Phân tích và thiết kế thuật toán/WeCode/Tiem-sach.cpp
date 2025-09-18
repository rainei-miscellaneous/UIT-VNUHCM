#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

struct arr {
    int h, s;
};

void solve() {
    // input
    int n, x;
    cin >> n >> x;
    vector<arr> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].h;
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i].s;
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    
    // dp[i][j], số trang tối đa khi duyệt tới phần tử i với tiền tối đa là j

    for(int i = 0; i <= x; i++)
        dp[0][i] = 0;

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= x; j++) {
            if(a[i].h <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i].h] + a[i].s);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][x];
}

int main() {
    // faster;
    solve();
    return 0;
}