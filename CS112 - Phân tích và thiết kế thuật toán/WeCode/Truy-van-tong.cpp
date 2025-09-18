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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    vector<ll> dp(n+1);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + a[i-1];
    }

    //test
    // for(int i = 0; i < n; i++)
    //     cout << dp[i] << ' ';

    for(int i = 0; i < t; i++) {
        int l, r;
        // l--; r--;
        cin >> l >> r;
        cout << dp[r] - dp[l-1] << '\n';
    }
        
}

int main() {
    faster;
    solve();
    return 0;
}