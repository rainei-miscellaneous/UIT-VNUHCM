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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    vector<int> dp(n + 1, 1);
    vector<int> prev(n + 1, -1);
    
    dp[1] = 1;
    int maxLen = 0, lastIdx = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i] && dp[i] < dp[j] + 1) {
                dp[i] = max(dp[i], dp[j] + 1);
                prev[i] = j;
            }
        }
        if(dp[i] > maxLen) {
            maxLen = dp[i];
            lastIdx = i;
        }
    }

    vector<int> ans;
    for(int i = lastIdx; i != -1; i = prev[i]) 
        ans.pb(a[i]);

    reverse(all(ans));

    cout << ans.size() << '\n';
    EACH(u, ans)
        cout << u << ' ';
}

int main() {
    // faster;
    solve();
    return 0;
}