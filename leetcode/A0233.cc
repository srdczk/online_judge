class Solution {
public:
    typedef long long LL;

    LL count(LL num) {
        LL res = 0;
        while (num) {
            res++;
            num /= 10;
        }
        return res;
    }

    LL pow(LL num) {
        LL res = 1;
        while (num) {
            num--;
            res *= (LL)10;
        }
        return res;
    }

    LL res(LL n) {
        if (n <= 0) return 0;
        if (n < 10) return 1;
        LL numOfTen = count(n) - 1;
        LL powTen = pow(numOfTen);
        LL other = n % powTen;

        LL firstNum = n / powTen;
        LL first = firstNum == 1 ? n % powTen + 1 : powTen;
        LL second = powTen / 10 * firstNum * numOfTen;
        return first + second + res(other);
    }

    int countDigitOne(int n) {
        return (int)res((LL)n);
    }
};