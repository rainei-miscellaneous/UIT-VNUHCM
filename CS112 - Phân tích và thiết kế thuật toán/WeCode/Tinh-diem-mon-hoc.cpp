#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

float roundFinalScore(float i) {
    float score = round(i * 1000) / 1000;
    score = round(score * 10)/10;
    return score;
}

void scoreGenerating(int curLength, int n, float totalScore, float finalScore, vector<int> weight, vector<float>& ans) {
    if(roundFinalScore(totalScore) > finalScore) {
        return;
    }

    if(curLength > n) {
        if(roundFinalScore(totalScore) == finalScore) {
            for(auto i : ans)
                cout << i << ' ';
            cout << '\n';
        }
        return;
    }

    for(float i = 0.25; i <= 10; i += 0.25) {
        float curScore = weight[curLength-1]/100.0 * i;
        ans.push_back(i);

        scoreGenerating(curLength + 1, n, curScore + totalScore, finalScore, weight, ans);

        ans.pop_back();
    }
}

void solve() {
    
    int n; float finalScore;
    cin >> n;

    vector<int> weight(10, 0);
    for(int i = 0; i < n; i++)
        cin >> weight[i];
    
    cin >> finalScore;

    vector<float> ans;

    scoreGenerating(1, n, 0.0, finalScore, weight, ans);
}

int main()
{
    faster;
	solve();
	return 0;
}