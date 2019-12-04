#include <bits/stdc++.h>

using namespace std;

bool isSame(string a, string b) {
    if (a.size() != b.size()) return 0;
    vector<int> cntA(10, 0), cntB(10, 0);
    for (auto &c : a) cntA[c - '0']++;
    for (auto &c : b) cntB[c - '0']++;
    for (int i = 0; i < cntA.size(); ++i) {
        if (cntA[i] != cntB[i]) return 0;
    }
    return 1;
}

string doubleRes(string s) {
    string res = "";
    int i = s.size() - 1, l = 0;
    while (i > -1) {
        int m = s[i--] - '0';
        if (2 * m + l > 9) {
            res = (char)('0' + 2 * m + l - 10) + res;
            l = 1;
        } else {
            res = (char)('0' + 2 * m + l) + res;
            l = 0;
        }
    }
    if (l) res = '1' + res;
    return res;
}

int main() {

    string s, p;
    cin >> s;
    p = doubleRes(s);
    if (isSame(s, p)) printf("Yes\n");
    else printf("No\n");
    printf("%s\n", p.data());
    return 0;
}
