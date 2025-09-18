#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n' << '\n' << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

bool flag = 0;

bool validNumber(string s) {
    return (s[0] != '0' || s == "0") && s.size() <= 18;
}

bool validSequence(vector<ll>& ans) {
    if(ans.size() < 3) return 0;

    for(int i = 0; i < ans.size()-2; i++) 
        if(ans[i] + ans[i+1] != ans[i+2])
            return 0;

    return 1;
}

void backtrack(int curState, string s, string prev, vector<ll>& ans) {
    // nếu duyệt tới cuối
        // nếu size(ans) >= 3   
            // for 2 số liên tiếp, nếu tổng = 3th thì tiếp until không được, return 0
            // return 1
    if(flag) return;    

    if(curState == s.size() && ans.size() >= 3 && validSequence(ans)) {
        flag = 1;
        return;
        // Test
        // EACH(u, ans)
        //     cout << u << ' ';
        // spacing;
    }

    for(int i = curState; i < s.size(); i++) {
        string num = s.substr(curState, i - curState + 1); // với mỗi vị trí, cắt thử các số với độ dài tăng dần
        if(!validNumber(num)) return;
        ll numLL = stoll(num);
        if(num.size() > s.size()/2) return;

        if (ans.size() >= 2 && numLL != ans[ans.size() - 1] + ans[ans.size() - 2]) {
            if (numLL > ans[ans.size() - 1] + ans[ans.size() - 2]) return;
            continue;
        }
        
        ans.pb(stoll(num));
        backtrack(i + 1, s, num, ans);
        ans.pop_back();
    }
}

void solve() {
    
    string n; cin >> n;

    vector<ll> ans;
    backtrack(0, n, "", ans);

    cout << (flag ? "true" : "false");
}

int main() {
    faster;
    solve();
    return 0;
}