#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

string s;

ll cal(ll l, ll r, char c) {
    if(c == '*') return l * r;
    if(c == '+') return l + r;
    if(c == '-') return l - r;
}

vector<ll> DaC(string s) {
    vector<ll> ans;
    bool flag = 0;

    // bài toán cơ sở
    for(int i = 0; i < s.size(); i++) {
        if(!(s[i] >= '0' && s[i] <= '9'))
            flag = 1;
    }

    if(!flag) {
        ans.pb(stoll(s));
        return ans;
    }

    // loop mọi dấu
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '*' || s[i] == '+' || s[i] == '-') {
            vector<ll> leftSubProb = DaC(s.substr(0, i));
            vector<ll> rightSubProb = DaC(s.substr(i+1));
            EACH(l, leftSubProb)
                EACH(r, rightSubProb)
                    ans.pb(cal(l, r, s[i]));
        }
    }
    
    return ans;
}

void solve() {
    // input
    cin >> s;

    // process
    vector<ll> ans = DaC(s);

    sort(all(ans));
    EACH(u, ans)
        cout << u << '\n';
}

int main() {
    faster;
    solve();
    return 0;
}
