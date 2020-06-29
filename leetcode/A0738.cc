class Solution {
public:
    void process(string &s) {
        if (s.size() < 2) return;
        int i = 1;
        for (; i < s.size(); ++i) {
            if (s[i] < s[i - 1]) break;
        }
        if (i == s.size()) return;
        int j = i - 1;
        while (j > -1 && s[j] == s[i - 1]) j--;
        s[j + 1]--;
        for (int p = j + 2; p < s.size(); ++p) s[p] = '9';
        i = 0;
        while (i < s.size() && s[i] == '0') i++;
        if (i == s.size()) s = "0";
        else s = s.substr(i);
    }
    int monotoneIncreasingDigits(int N) {
        auto s = to_string(N);
        process(s);
        return stoi(s);
    }
};