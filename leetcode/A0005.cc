class Solution {
public:
    static const int kMaxV = 2010;
    int pArray[kMaxV];
    int pString[kMaxV];
    int size;
    void process(string &s) {
        size = 2 * s.length() + 1;
        for (int i = 0; i < size; ++i) {
            if (!(i % 2)) pString[i] = '#';
            else pString[i] = s[i / 2];
        }
    }
    string longestPalindrome(string s) {
        process(s);
        int start = 0, length = 0, R = -1, C = -1;
        for (int i = 0; i < size; ++i) {
            pArray[i] = R > i ? min(R - i, pArray[2 * C - i]) : 1;
            while (i + pArray[i] < size && i - pArray[i] > -1) {
                if (pString[i + pArray[i]] == pString[i - pArray[i]]) pArray[i]++;
                else break;
            }
            if (i + pArray[i] > R) {
                R = i + pArray[i];
                C = i;
            }
            if (pArray[i] - 1 > length) {
                length = pArray[i] - 1;
                start = (i - pArray[i] + 1) / 2;
            }
        }
        return s.substr(start, length);

    }
};