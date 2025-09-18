#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<int> job;
ll timeMIN = LONG_LONG_MAX;
vector<int> ans;


ll findMaxTime(const vector<ll>& totalTime) {
    return *max_element(totalTime.begin(), totalTime.end());
}
vector<ll> totalTime;
void jobSchedulingGenerating(int curJob, int numJob, int numMachine, vector<int> index) {
    for (int machine = 0; machine < numMachine; machine++) {
        if (curJob == numJob) {
            for (int jobs = 0; jobs < numJob; jobs++)
                totalTime[index[jobs]] += job[jobs];

            ll maxTime = findMaxTime(totalTime);

            if (maxTime < timeMIN) {
                timeMIN = maxTime;
                // cout << timeMIN << '\n';
                ans.clear();
                for (auto i : index)
                    ans.push_back(i);
            }
            fill(totalTime.begin(), totalTime.end(), 0);
            return;
        } else {
            index[curJob] = machine;
            jobSchedulingGenerating(curJob + 1, numJob, numMachine, index);
        }
    }
}

void solve() {
    int numJob, numMachine;
    cin >> numJob >> numMachine;
    job.resize(numJob);
    for (int i = 0; i < numJob; i++) {
        cin >> job[i];
    }

    // Khong can sort, vi sort cung cha giup ich duoc gi
    
    vector<int> index;
    totalTime.resize(numMachine, 0);
    index.resize(numJob, 0);
    
    jobSchedulingGenerating(1, numJob, numMachine, index);

    for (auto i : ans)
        cout << i << ' ';
}

int main() {
    faster;
    solve();
    return 0;
}