#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

void permutationGenerating(int curLength, string n, vector<int> permutation, vector<int>& ans, vector<bool>& check) {
    for(int i = 0; i < permutation.size(); i++) {
        int num = permutation[i];
        if(!check[num]) {
            check[num] = 1;
            ans.push_back(num);

            if(curLength < n.size()) 
                permutationGenerating(curLength + 1, n, permutation, ans, check);
            else {
                for(auto i : ans)
                    cout << i;
                cout << '\n';
            }

            check[num] = 0;
            ans.pop_back();
        }
    }
}

void solve() {
    string n; 
    cin >> n;
    vector<int> permutation;
    vector<int> ans;
    vector<bool> check(n.size(), 0);
    for(int j = n.size()-1; j >= 0; j--)
        permutation.push_back(int(n[j]) - 48); // trừ difference từ char sang int

    permutationGenerating(1, n, permutation, ans, check);
}

int main()
{
    faster;
	solve();
	return 0;
}