#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

bool flag = 0;

void backtrack(int curRow, int maxRow, vector<bool>& isCol, vector<pair<int,int>>& diagonal, vector<vector<char>>& ans) {
    if(flag) return;
    if(curRow == maxRow) {
        EACH(d, diagonal) {
            ans[d.first][d.second] = 'X';
            flag = 1;
        }
        return;
    }

    for(int col = 0; col < maxRow; col++) {
        if(isCol[col]) continue;
        
        bool foundExistOnDiagonal = 0;
        EACH(d, diagonal) {
            if(abs(curRow - d.first) == abs(col - d.second)) {
                foundExistOnDiagonal = 1;
                break;
            }
        }

        if(foundExistOnDiagonal) continue;
        // if(col == maxRow - 1 && !foundExistOnDiagonal) return;

        isCol[col] = 1;
        diagonal.push_back({curRow, col});
        // cout << curRow << ' ' << col; spacing;
        backtrack(curRow + 1, maxRow, isCol, diagonal, ans);
        isCol[col] = 0;
        diagonal.pop_back();
    }
}

void solve() {
    // input
    int n; cin >> n;
    vector<pair<int,int>> diagonal;
    vector<vector<char>> sol(n, vector<char>(n, '.'));
    vector<bool> isCol(n, 0);
    backtrack(0, n, isCol, diagonal, sol);

    if(n > 1 && n < 4) cout << "";
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << sol[i][j];
            cout << '\n';
        }
    }
}

int main() {
    // faster;
    solve();
    return 0;
}