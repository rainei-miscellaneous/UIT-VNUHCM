#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int findMinIndex(vector<ll> totalTime) {
    int curIndex = 0;
    ll curMinTime = LONG_LONG_MAX;
    for(int i = 0; i < totalTime.size(); i++) {
        if(totalTime[i] < curMinTime) {
            curMinTime = totalTime[i];
            curIndex = i;
        }
    }
    return curIndex;
}

void solve() {
    int n, m;
    vector<pair<int, int>> job;
    cin >> n >> m;
    job.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> job[i].first;
        job[i].second = i;
    }

    sort(job.begin(), job.end(), cmp);

    vector<ll> totalTime(m, 0);
    vector<int> ans;
    ans.resize(n);

    for(int i = 0; i < n; i++) {
        int idx = findMinIndex(totalTime); // chỉ số máy rảnh hiện tại
        totalTime[idx] += job[i].first; // thời gian máy đó tăng lên -> máy đó làm việc
        ans[job[i].second] = idx; // công việc thứ i do máy đó đảm nhận
    }
            
    for(auto i:ans)
        cout << i << ' ';
}

int main()
{
    faster;
	solve();
	return 0;
}