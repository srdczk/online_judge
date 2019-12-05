#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> m;

void toLower(string &s) {
    for (auto &c : s) {
        if (c >= 'A' && c <= 'Z') c = 'a' + c - 'A';
    }
}

int main() {
    string s;
    getline(cin, s);
    toLower(s);
    int i = 0;
    while (i < s.length()) {
        while (i < s.length() && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) i++;
        if (i > s.length() - 1) break;
        int len = 1;
        while (i + len < s.length() && ((s[i + len] >= 'a' && s[i + len] <= 'z') || (s[i + len] >= '0' && s[i + len] <= '9'))) len++;
        m[s.substr(i, len)]++;
        i += len;
    }
    string p;
    int cnt = -1;
    for (auto &it : m) {
        //cout << it.first << " " << it.second << endl;
        if (it.second > cnt) {
            cnt = it.second;
            p = it.first;
        }
    }
    printf("%s %d\n", p.data(), cnt);
    return 0;
}
