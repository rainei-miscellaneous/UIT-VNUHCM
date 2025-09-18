#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define spacing cout << '\n' << '\n' << '\n';
#define all(x) (x).begin(), (x).end()
#define EACH(u, v) for (auto &u : v)

int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leapYear(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

bool specialLeapYear(int year) {
    return (year && year % 3328 == 0);
}

void dayGenerating(int curState, const string &s, vector<bool> &check, set<string> &ans, vector<char> &temp) {
    if (curState > s.size()) {
        string tempAns = "";
        EACH(i, temp)
        tempAns += i;

        string yearStr = tempAns.substr(0, 4);
        string monthStr = tempAns.substr(4, 2);
        string dayStr = tempAns.substr(6, 2);

        int year = stoi(yearStr);
        int month = stoi(monthStr);
        int day = stoi(dayStr);

        // nếu năm nhuận/siêu nhuận -> tháng 2 bị ảnh hưởng
        // tháng phải từ 1 -> 12
        // ngày phải > 0 && < daysOfMonth[tháng];

        if(year < 1) return;
        if (month < 1 || month > 12) return;

        int limitDays = daysOfMonth[month];
        if (leapYear(year) && month == 2) limitDays = 29;
        if (specialLeapYear(year) && month == 2) limitDays = 30;
        if (day < 1 || day > limitDays) return;

        ans.insert(yearStr + " " + monthStr + " " + dayStr);
    } else {
        for (int i = 0; i < s.size(); i++) {
            if (!check[i]) {
                check[i] = 1;
                temp.pb(s[i]);
                dayGenerating(curState + 1, s, check, ans, temp);
                temp.pop_back();
                check[i] = 0;
            }
        }
    }
}

void solve() {
    string y, m, d;
    cin >> y >> m >> d;

    string YearMonthDay = y + m + d;
    set<string> ans;
    vector<bool> check(YearMonthDay.size(), 0);
    vector<char> temp;

    dayGenerating(1, YearMonthDay, check, ans, temp);

    cout << ans.size() << '\n';
    EACH(i, ans)
    cout << i << '\n';
}

int main() {
    faster;
    solve();
    return 0;
}
