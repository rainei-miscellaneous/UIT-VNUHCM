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
    vector<int> a(n + 1);

    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // dp[i] = 1 nếu tạo được tổng i else 0
    vector<bool> dp(sum + 1, 0);
    dp[sum] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= dp.size(); j++) {
            if(dp[j])   
                dp[j-a[i]] = 1;
        }
    }
    
    int ans = 0;
    for(int j = 1; j <= dp.size(); j++) 
        if(dp[j])   
            ans++;
    

    cout << ans << '\n';
    for(int j = 1; j <= dp.size(); j++) 
        if(dp[j])   
            cout << j << ' ';
}   

int main() {
    // faster;
    solve();
    return 0;
}