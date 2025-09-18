#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> mat, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

void printAns(vector<int> ans) {
    for(auto i : ans)
        cout << i << ' ';
}

void solve() {
    int col, row;
    cin >> col >> row;
    vector<vector<int>> job(row, vector<int>(col, 0));
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> job[i][j];
        }
    }

    // Test
    // printMatrix(job, row, col);

    // Ứng mỗi việc, mỗi máy có thời gian hoạt động riêng của nó -> Không thể sort
    vector<int> ans(col);
    vector<ll> machineTotalTime(row, 0);

    for(int j = 0; j < col; j++) { // Xét công việc j
        int machineIndex = 0;
        ll minTime = LONG_LONG_MAX;

        for(int i = 0; i < row; i++) { // Xét máy i
            int curTime = job[i][j];
            if(machineTotalTime[i] + curTime < minTime) {
                minTime = machineTotalTime[i] + curTime;
                machineIndex = i;
            }
        }
        machineTotalTime[machineIndex] += job[machineIndex][j];
        ans[j] = machineIndex;
        
        //Test
        // cout << "j" << j << ": ";
        // for(int i = 0; i < row; i++) 
        //     cout << machineTotalTime[i] << ' ';
        // cout << '\n';
    }

    printAns(ans);
}

int main()
{
    faster;
	solve();
	return 0;
}