#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;

string process(string a) {
    bool x = a[0] == '+' ? 1 : 0;
    int p = a.find('E');
    int e = stoi(a.substr(p + 1));
    string s = a.substr(1, p - 1);
    if (!e) return x ? s : '-' + s;
    else if (e > 0) {
        if (e < s.length() - 2) {
            s.erase(s.begin() + 1);
            string res = "";
            if (!x) res += '-';
            res += s.substr(0, 1 + e);
            res += '.';
            res += s.substr(1 + e);
            return res;
        } else {
            int sp = e - s.length() + 2;
            s.erase(s.begin() + 1);
            string res = "";
            if (!x) res += '-';
            res += s;
            for (int i = 0; i < sp; ++i) {
                res += '0';
            }
            return res;
        }
    } else {
        s.erase(s.begin() + 1);
        string res = "0.";
        for (int i = 0; i < -e - 1; ++i) {
            res += '0';
        }
        res += s;
        if (!x) res = '-' + res;
        return res;
    }
}

int main() {
    char a[maxV];
    scanf("%s", a);
    printf("%s\n", process(a).data());
    return 0;
}