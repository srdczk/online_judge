#include <bits/stdc++.h>
using namespace std;
const int BUFSIZE = 1024;
int k;
string process(string s) {
    if (s[0] == '-') return '-' + process(s.substr(1));
    if (s[0] == '+') return process(s.substr(1));
    int h = 0;
    while (h < s.size() && s[h] == '0') h++;
    if (h == s.size()) {
        string sp = "";
        while (sp.size() < k) sp += '0';
        return "0." + sp + "*10^0";
    }
    s = s.substr(h);
    int p = s.find('.');
    if (p == string::npos) {
        int len = s.length();
        while (s.size() < k) s += '0';
        return "0." + s.substr(0, k) + "*" + "10^" + to_string(len);
    } else {
        if (s[0] == '.') {
            int cnt = 0, h = 1;
            while (h < s.length() && s[h] == '0') {
                h++;
                cnt++;
            }
            string sp = h == s.length() ? "" : s.substr(h);
            while (sp.size() < k) sp += '0';
            if (h == s.length()) return "0." + sp + "*10^0";
            return "0." + sp.substr(0, k) + "*" + "10^" + to_string(-cnt);
        } else {
            int len = p;
            s.erase(s.begin() + p);
            while (s.size() < k) s += '0';
            return "0." + s.substr(0, k) + "*" + "10^" + to_string(len);
        }
    }
}

int main() {
    scanf("%d", &k);
    char a[BUFSIZE], b[BUFSIZE];
    scanf("%s%s", a, b);
    string sa = process(a), sb = process(b);
    if (sa == sb) {
        printf("YES %s\n", sa.data());
    } else printf("NO %s %s\n", sa.data(), sb.data());
    return 0;
}