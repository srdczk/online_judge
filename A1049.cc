#include <bits/stdc++.h>

using namespace std;

long length(long n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 10;
    }
    return ans;
}

long res(long n) {
    if (n < 10) return !n ? 0 : 1;
    long len = length(n);
    long p = (long) (pow(10, len - 1));
    long first = n / p;
    // 若果第一个数为 1, 则 第一个数为 1 的只有 (n % p + 1)
    long firstNum = first == 1 ? (n % p + 1) : p;
    // 剩下几位每一位在 一个 p 中都有 p / 10 个
    long secondNum = (long)(first * (long) (len - 1) * p / (long) 10);
    return (firstNum + secondNum + res(n % p));
}


int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", res(n));
    return 0;
}