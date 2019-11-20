#include <bits/stdc++.h>

using namespace std;

bool pd(long a, long b, long c) {
    long r = a + b;
    if (a > 0 && b > 0 && r <= 0) return 1;
    else if (a < 0 && b < 0 && r >= 0) return 0;
    return r > c;
}

int main() {
    int n;
    long a, b, c;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; ++i) {
        printf("Case #%d: ", i);
        scanf("%ld%ld%ld", &a, &b, &c);
        if (pd(a, b, c)) printf("true\n");
        else printf("false\n");
    }
    return 0;
}