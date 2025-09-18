#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n' << '\n' << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

int m8x[] = {-1, 1, 0, 0, -1, -1, 1, 1}; 
int m8y[] = {0, 0, 1, -1, -1, 1, -1, 1};

bool isValid(int x, int y, int m, int n, vector<vector<int>>& a, vector<vector<bool>>& visited) {
    return (x >= 0 && x < m && y >= 0 && y < n && !a[x][y] && !visited[x][y]);
}

void Dijkstra(int xStart, int yStart, int xFin, int yFin, int m, int n, vector<vector<int>>& a, vector<vector<bool>>& visited, bool& found, int& totalTime) {
    using T = pair<int, pair<int, int>>;
    vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
    priority_queue<T, vector<T>, greater<T>> q;

    dis[xStart][yStart] = 0;
    q.push({dis[xStart][yStart], {xStart, yStart}});
    visited[xStart][yStart] = 1;

    while (!q.empty()) {
        auto current = q.top();
        q.pop();

        int tempX = current.second.first;
        int tempY = current.second.second;
        int curTime = current.first;
        if (tempX == xFin && tempY == yFin) {
            found = 1;
            totalTime = curTime;
            return;
        }

        for (int i = 0; i < 8; i++) {
            int newX = tempX + m8x[i];
            int newY = tempY + m8y[i];

            if (isValid(newX, newY, m, n, a, visited)) {
                if(dis[tempX][tempY] + 1 < dis[newX][newY]) {
                    dis[newX][newY] = dis[tempX][tempY] + 1;
                    visited[newX][newY] = 1;
                    q.push({dis[newX][newY], {newX, newY}});
                }
            }
        }
    }
}

void solve() {
    int m, n, xStart, yStart, xFin, yFin;
    cin >> m >> n >> xStart >> yStart >> xFin >> yFin;

    xStart = m - xStart - 1; // chá»nh sá»­a láº¡i toáº¡ Äá»
    xFin = m - xFin - 1; // chá»nh sá»­a láº¡i toáº¡ Äá»
    
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool found = 0;
    int totalTime = -1;

    Dijkstra(xStart, yStart, xFin, yFin, m, n, a, visited, found, totalTime);
    cout << (found ? totalTime : -1) << endl;
}

int main() {
    // faster;
    solve();
    return 0;
}