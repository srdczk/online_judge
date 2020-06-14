#include <bits/stdc++.h>

using namespace std;

string s;
int i = 0;

string add(string &a, string &b);
string pro(string &a, string &b);

void process(string &s);

string exp();
string fac();
string num();



int main() {
    getline(cin, s);
    getchar();
    process(s);
    auto res = exp();
    if (res.length() > 4) res = res.substr(res.length() - 4);
    int p = 0;
    while (p < res.length() && res[p] == '0') p++;
    if (p == res.length()) printf("0\n");
    else printf("%s\n", res.substr(p).data());
    return 0; 
}

string add(string &a, string &b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, l = 0;
    while (i > -1 && j > -1) {
        int m = a[i--] - '0', n = b[j--] - '0';
        if (m + n + l < 10) {
            res.push_back((char)('0' + m + n + l));
            l = 0;
        } else {
            res.push_back((char)('0' + m + n + l - 10));
            l = 1;
        }
    }
    while (i > -1) {
        int m = a[i--] - '0';
        if (m + l < 10) {
            res.push_back((char)('0' + m + l));
            l = 0;
        } else {
            res.push_back((char)('0' + m + l - 10));
            l = 1;
        }
    }
    while (j > -1) {
        int m = b[j--] - '0';
        if (m + l < 10) {
            res.push_back((char)('0' + m + l));
            l = 0;
        } else {
            res.push_back((char)('0' + m + l - 10));
            l = 1;
        }
    }
    if (l) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}

string pro(string &a, string &b) {
    string res = "0";
    for (int i = 0; i < b.size(); ++i) {
        int num = b[b.size() - 1 - i] - '0';
        string tmp = "0";
        for (int j = 0; j < num; ++j) tmp = add(tmp, a);
        for (int j = 0; j < i; ++j) tmp.push_back('0');
        res = add(res, tmp);
    }
    return res;
}

void process(string &s) {
    auto it = s.begin();
    while (it != s.end()) {
        if (*it == ' ') it = s.erase(it);
        else ++it;
    }
}

string exp() {
    auto res = std::move(fac());
    while (i < s.length()) {
        char c = s[i++];
        if (c == '+') {
            auto f = fac();
            res = add(res, f);
        } else break;
    }
    return res;
}
string fac() {
    auto res = std::move(num());
    while (i < s.length()) {
        char c = s[i];
        if (c == '*') {
            i++;
            auto f = num();
            res = pro(res, f);
        } else break;
    }
    return res;
}
string num() {
    string res;
    while (i < s.length() && (s[i] >= '0' && s[i] <= '9')) res.push_back(s[i++]);
    return res;
}