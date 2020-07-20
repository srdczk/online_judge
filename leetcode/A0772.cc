class Solution {
public:

    typedef long long LL;

    int i = 0;

    string s;

    LL exp() {
        // before +, -
        LL res = fac();
        while (i < s.length()) {
            if (s[i] == '+') {
                i++;
                res += fac();
            } else if (s[i] == '-') {
                i++;
                res -= fac();
            } else break;
        }
        return res;
    }

    LL fac() {
        int res = num();
        while (i < s.length()) {
            if (s[i] == '*') {
                i++;
                res *= num();
            } else if (s[i] == '/') {
                i++;
                res /= num();
            } else break;
        }
        return res;
    }

    LL num() {
        if (isdigit(s[i])) {
            LL cnt = 0;
            while (i < s.length() && isdigit(s[i])) {
                cnt = cnt * (LL)10 + (LL)(s[i++] - '0');
            }
            return cnt;
        } else {
            i++;
            LL res = exp();
            i++;
            return res;
        }
    }

    int calculate(string n) {
        auto it = n.begin();
        while (it != n.end()) {
            if (*it == ' ') it = n.erase(it);
            else ++it;
        }
        s = n;
        return (int)exp();
    }
};