#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

struct arr {
    int st, fi, tc;
};

bool compare(const arr &a, const arr &b) {
    if (a.fi == b.fi) {
        return a.st < b.st;
    }
    return a.fi < b.fi;
}

int binSearch(const vector<arr> &a, int idx) {
    int l = 1, r = idx - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid].fi < a[idx].st) {
            if (a[mid + 1].fi < a[idx].st) // nếu tồn tại tốt hơn
                l = mid + 1; // tìm tiếp
            else
                return mid;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

void solve() {
    // input
    int n; 
    cin >> n;
    vector<arr> a(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));

    for(int i = 1; i <= n; i++) 
        cin >> a[i].st >> a[i].fi >> a[i].tc;

    sort(all(a), compare);

    // EACH(u, a)
    //     cout << u.st << ' ' << u.fi << ' ' << u.tc << '\n';

    // dp[i][j] đồ án tối đa khi xét tới môn thứ i, j là 1.chọn / 0.không

    dp[1][1] = a[1].tc;

    for(int i = 2; i <= n; i++) {
        int mid = binSearch(a, i);
        if(mid != -1)
            dp[i][1] = max(dp[mid][0], dp[mid][1]) + a[i].tc;
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], (ll)a[i].tc});
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    // faster;
    solve();
    return 0;
}