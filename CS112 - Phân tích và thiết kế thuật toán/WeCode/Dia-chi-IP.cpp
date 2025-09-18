#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <bits/stdc++.h>
using namespace std;

bool validIP(string n) {
    vector<int> index;
    for(int i = 0; i < n.size(); i++) {
        if(n[i] == '.')
            index.push_back(i);
    }

    if(index.size() != 3) return 0;

    index.insert(index.begin(), -1); // Đầu vector là -1, tương ứng với đầu chuỗi không có dấu .
    index.push_back(n.size()); // Cuối vector là size string, tương ứng với cuối chuỗi có dấu .

    for(int j = 0; j < index.size() - 1; j++) {
        int id1 = index[j]; 
        int id2 = index[j+1];

        if(id2 - id1 == 1) return 0; // Nếu 2 dấu chấm liền kề -> Sai

        if(id2 - id1 > 2 && n[id1+1] == '0') return 0; // Nếu có 2 số ở giữa 2 dấu chấm, số đầu là số 0 thì sai 

        int sum = 0;
        for(int t = id1 + 1; t < id2; t++) {
            sum = sum * 10 + (n[t] - '0');
        }
        if(sum > 255) return 0;
    }
    return 1;
}

void ipGenerating(int curLength, string ans, vector<bool> check, int lastDotPos) {
    for(int i = lastDotPos + 1 ; i < ans.size(); i++) { // Thử với mỗi vị trí, đặt dấu .
        if(curLength < 4) { // Nếu chưa đặt đủ 3 chấm thì tiếp tục
            if(!check[i]) {
                check[i] = 1;
                ans.insert(i, 1, '.');
                
                ipGenerating(curLength + 1, ans, check, i);  

                ans.erase(i, 1);
                check[i] = 0;
            }
        } else {
            if (validIP(ans)) {
                cout << ans << '\n';
            }
            return;
        }
    }
}

void solve() {
    string n; 
    cin >> n;

    // Setup
    
    // Không quan trọng thứ tự
    // Mỗi địa chỉ ip cần 4 dấu chấm

    // Test
    // if(validIP(n)) {
    //     cout << 1;
    // } else {
    //     cout << 0;
    // }
    vector<bool> check(n.size()+3, 0);
    // map<string, bool> mapping;
    if(n.size() < 4 || n.size() > 12) {
        cout << "";
    } else {
        ipGenerating(1, n, check, 0);
    }
}

int main()
{
    faster;
	solve();
	return 0;
}