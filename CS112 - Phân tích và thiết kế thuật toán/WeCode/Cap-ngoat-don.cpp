#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

void bracketGenerating(int curLength, int n, vector<char>& ans, vector<char> initBracket, int countLeftBracket, int countRightBracket) {
    for(int i = 0; i < 2; i++) {
        if(countLeftBracket > n || countRightBracket > n)
            return;
        if(countRightBracket > countLeftBracket)
            return;
        
        if(curLength <= 2 * n) {
            ans.push_back(initBracket[i]);
            bracketGenerating(curLength + 1, n, ans, initBracket, countLeftBracket + !i, countRightBracket + i);
            ans.pop_back();
        } else {
            if(countLeftBracket == countRightBracket) {
                if(ans[0] == '(' && ans[2*n-1] == ')') {
                    for(auto j : ans)
                        cout << j;
                    cout << '\n';
                    return;
                }
            }
        }
    }
}

void solve() {
    int n; 
    cin >> n;

    // Setup
    vector<char> ans;
    vector<char> initBracket = {'(', ')'};
    bracketGenerating(1, n, ans, initBracket, 0, 0);
}

int main()
{
    faster;
	solve();
	return 0;
}