#include <bits/stdc++.h>

using namespace std;
const int BUFSIZE = 110;
unordered_set<string> ss;
vector<string> als;

int process(string s) {
    return stoi(s.substr(6, 2)) + stoi(s.substr(4, 2)) * 32 + stoi(s.substr(0, 4)) * 32 * 13;
}

int main() {
    int n, m;
    scanf("%d", &n);
    char s[BUFSIZE];
    while (n--) {
        scanf("%s", s);
        ss.insert(string(s));
    }
    scanf("%d", &m);
    int cnt = 0;
    int MIN = INT_MAX;
    string res;
    while (m--) {
        scanf("%s", s);
        string a(s);
        als.push_back(a);
        if (ss.count(a)) {
            cnt++;
            if (process(a.substr(6, 8)) < MIN) {
                MIN = process(a.substr(6, 8));
                res = a;
            }
        }
    }
    if (cnt) printf("%d\n%s\n", cnt, res.data());
    else {
        for (auto &c : als) {
            if (process(c.substr(6, 8)) < MIN) {
                MIN = process(c.substr(6, 8));
                res = c;
            }
        }
        printf("0\n%s\n", res.data());
    }
    return 0;
}