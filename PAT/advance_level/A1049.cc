#include <bits/stdc++.h>

using namespace std;

long length(long n) {
    long cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

long res(long n) {
    if (!n) return 0;
    if (n < 10) return 1;
    long len = length(n);
    long x = (long)(pow(10, len - 1));
    long first = n / x;
    long firstNum = first == 1 ? n % x + 1 : x;
    long otherNum = first * (x / 10) * (len - 1);
    return firstNum + otherNum + res((long)(n % (first * x)));
}

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", res(n));
    return 0;
}
