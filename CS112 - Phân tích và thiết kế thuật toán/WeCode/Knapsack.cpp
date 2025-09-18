#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

struct arr {
    int w, v;
};

void solve() {
    // input
    int n, x;
    cin >> n >> x;
    vector<arr> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].v;
    }
    
    vector<ll> dp(x + 1, 0);
    
    // dp[i], value tối đa với weight tối đa là i

    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= 1; j--) {
            if(a[i].w <= j)
                dp[j] = max(dp[j], dp[j-a[i].w] + a[i].v);
            else continue;
        }
    }

    cout << dp[x];
}

int main() {
    // faster;
    solve();
    return 0;
}