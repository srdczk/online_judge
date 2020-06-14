class Solution {
public:
    typedef long long LL;
    string ss;
    int i = 0;

    LL exp() {
        LL res = fac();
        while (i < ss.length()) {
            char c = ss[i++];
            if (c == '+') {
                res += fac();
            } else if (c == '-') {
                res -= fac();
            } else break;
        }
        return res;
    }

    LL fac() {
        LL res = num();
        while (i < ss.length()) {
            char c = ss[i];
            if (c == '*') {
                i++;
                res *= num();
            } else if (c == '/') {
                i++;
                res /= num();
            } else break;
        }
        return res;
    }

    LL num() {
        LL res = 0;
        if (ss[i] >= '0' && ss[i] <= '9') {
            while (i < ss.length() && (ss[i] >= '0' && ss[i] <= '9')) {
                res = res * (LL)10 + (LL)(ss[i++] - '0');
            }
        } else {
            i++;
            res = exp();    
        }
        return res;
    }

    int calculate(string s) {
        this->ss = std::move(s);
        auto it = ss.begin();
        while (it != ss.end()) {
            if (*it == ' ') it = ss.erase(it);
            else ++it;
        }
        return (int)exp();
    }
};