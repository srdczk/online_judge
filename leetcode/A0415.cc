class Solution {
public:
    string addStrings(string num1, string num2) {
        // not - begin,
        string res = "";
        int i = num1.length() - 1, j = num2.length() - 1, l = 0;
        while (i > -1 && j > -1) {
            int m = num1[i--] - '0', n = num2[j--] - '0';
            if (m + n + l > 9) {
                res += ((char)(m + n + l - 10 + '0'));
                l = 1;
            } else {
                res += ((char)(m + n + l + '0'));
                l = 0;
            }
        }
        while (i > -1) {
            int m = num1[i--] - '0';
            if (m + l > 9) {
                res += ((char)(m + l - 10 + '0'));
                l = 1;
            } else {
                res += ((char)(m + l + '0'));
                l = 0;
            }
        }
        while (j > -1) {
            int m = num2[j--] - '0';
            if (m + l > 9) {
                res += ((char)(m + l - 10 + '0'));
                l = 1;
            } else {
                res += ((char)(m + l + '0'));
                l = 0;
            }
        }
        if (l) res += ('1');

        reverse(res.begin(), res.end());
        return res;
    }
};