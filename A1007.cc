#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int res = INT_MIN, sum = 0;
    int b = INT_MIN, e, rb, re, p = INT_MIN, q;
    while (n--) {
        int x;
        scanf("%d", &x);
        sum += x;
        if (p == INT_MIN) p = x;
        q = x;
        if (b == INT_MIN) b = x;
        e = x;
        if (sum > res) {
            res = sum;
            rb = b;
            re = e;
        }
        if (sum < 0) {
            sum = 0;
            b = INT_MIN;
        }
    }
    if (res < 0) printf("0 %d %d\n", p, q);
    else printf("%d %d %d\n", res, rb, re);
    return 0;
}