#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

int binSearch(vector<int>& t, int x) {
    int l = 0, r = t.size();
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(t[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void solve() {
    // input
    using T = pair<int, int>;
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 1);
    vector<int> temp;

    // dp[i] là LIS tại vị trí i
    
    for(int i = 1; i <= n; i++) {   
        int mid = binSearch(temp, a[i]);
        if(mid == temp.size())
            temp.pb(a[i]);
        else
            temp[mid] = a[i];

        dp[i] = mid + 1;
    }

    cout << *max_element(all(dp));
}

int main() {
    // faster;
    solve();
    return 0;
}