#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        return process(static_cast<uint64_t>(n));
    }
private:
    uint64_t process(uint64_t n) {
        if (!n) return 0;
        if (n < 10) return 1;
        uint64_t count = cnt(n);
        uint64_t x = pow(10, count - 1);
        uint64_t first = n / x;
        uint64_t one = first == 1 ? n % x + 1 : x;
        uint64_t other = first * x / 10 * (count - 1);
        return one + other + process(n - first * x);
    }
    uint64_t cnt(uint64_t n) {
        int res = 0;
        while (n) {
            ++res;
            n /= 10;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.countDigitOne(343434);
    return 0;
}
