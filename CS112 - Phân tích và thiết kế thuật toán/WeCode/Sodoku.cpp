#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

void backtrack(int curIndex, vector<pair<int, int>> pos, vector<int>& ans, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<vector<int>>>& bigSquare) {
    if(curIndex == pos.size()) {    
        return;
    }

    // Với mỗi X, xem xét xem có thể điền số nào
    auto t = pos[curIndex];
    int x = t.first;
    int y = t.second;
    for(int i = 1; i <= 9; i++) {
        if(row[x][i] || col[y][i] || bigSquare[x/3][y/3][i]) {
            continue; // Những số mà hàng/cột/ô của nó đã có rồi thì skip
            // continue;
        }
        ans.pb(i);
        row[x][i] = 1;
        col[y][i] = 1;
        bigSquare[x/3][y/3][i] = 1;
        // cout << i << ' ';   
        backtrack(curIndex + 1, pos, ans, row, col, bigSquare);
        ans.pop_back();
        row[x][i] = 0;
        col[y][i] = 0;
        bigSquare[x/3][y/3][i] = 0;
    }
}

void solve() {
    // input
    vector<vector<int>> row(9, vector<int>(10, 0));
    vector<vector<int>> col(9, vector<int>(10, 0));
    vector<vector<vector<int>>> bigSquare(9, vector<vector<int>>(9, vector<int>(10, 0)));

    vector<pair<int, int>> pos;
    vector<vector<char>> adj(9, vector<char>(9));

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            char c;
            cin >> c;
            adj[i][j] = c;
            if(c == 'X')
                pos.pb({i, j});
            else {
                row[i][c-'0'] = 1;
                col[j][c-'0'] = 1;
                bigSquare[i/3][j/3][c-'0'] = 1;
            }
        }
        spacing;
    }
    
    vector<int> ans;
    backtrack(0, pos, ans, row, col, bigSquare);

    if(pos.empty()) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << adj[i][j] << ' ';
            }
            cout << endl;
        }
    } else {
        int num = 0;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(adj[i][j] == 'X') {
                    cout << ans[num] << ' ';
                    num++;
                } else {
                    cout << adj[i][j] << ' ';
                }
            }
            cout << '\n';
        }
    }
}

int main() {
    // faster;
    solve();
    return 0;
}