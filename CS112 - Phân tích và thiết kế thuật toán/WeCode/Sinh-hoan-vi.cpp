#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

void permutationGenerating(int currentLength, int n, vector<bool>& check, vector<int>& permutation) {
    for(int i = 1; i <= n; i++) {
        if(!check[i]) {
            check[i] = 1;
            permutation.push_back(i);
            
            if(currentLength < n)
                permutationGenerating(currentLength + 1, n, check, permutation);    
            else {
                for(auto i : permutation)
                    cout << i << ' ';
                cout << '\n';
            }

            permutation.pop_back();
            check[i] = 0; 
        }
    }
}

void solve() {
    int n; 
    cin >> n;
    vector<int> permutation;
    vector<bool> check(n + 1, 0);
    permutationGenerating(1, n, check, permutation);
}

int main()
{
    faster;
	solve();
	return 0;
}