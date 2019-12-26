#include <bits/stdc++.h>

using namespace std;

const int BUFSIZE = 1010;

bool isPali(const string &a) {
    int i = 0, j = a.size() - 1;
    while (i < j) {
        if (a[i++] != a[j--]) return 0;
    }
    return 1;
}

string add(const string &a, const string &b) {
    string res = "";
    int i = a.size() - 1, j = b.size() - 1, l = 0;
    while (i > -1 && j > -1) {
        int m = a[i--] - '0', n = b[j--] - '0';
        if (m + n + l > 9) {
            res = (char)('0' + m + n + l - 10) + res;
            l = 1;
        } else {
            res = (char)('0' + m + n + l) + res;
            l = 0;
        }
    }
    while (i > -1) {
        int m = a[i--] - '0';
        if (m + l > 9) {
            res = (char)('0' + m + l - 10) + res;
            l = 1;
        } else {
            res = (char)('0' + m + l) + res;
            l = 0;
        }
    }
    while (j > -1) {
        int m = b[j--] - '0';
        if (m + l > 9) {
            res = (char)('0' + m + l - 10) + res;
            l = 1;
        } else {
            res = (char)('0' + m + l) + res;
            l = 0;
        }
    }
    if (l) res = '1' + res;
    return res;
}

int main() {
    int cnt = 0;
    bool x = 1;
    char s[BUFSIZE];
    scanf("%s", s);
    string a(s);
    if (isPali(a)) {
        printf("%s is a palindromic number.\n", a.data());
        return 0;
    }
    while (x && cnt < 10) {
        string p = a;
        reverse(p.begin(), p.end());
        string ap = add(a, p);
        printf("%s + %s = %s\n", a.data(), p.data(), ap.data());
        cnt++;
        a = ap;
        if (isPali(a)) {
            x = 0;
        }
    }
    if (!x) printf("%s is a palindromic number.\n", a.data());
    else printf("Not found in 10 iterations.\n");
    return 0;
}
