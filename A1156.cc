#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n < 1) return 0;
    if (n == 1) return 0;
    if (n < 4) return 1;
    for (int i = 2; i <= (int)sqrt(n); ++i) {
        if (!(n % i)) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    if (isPrime(n) && (isPrime(n - 6) || isPrime(n + 6))) {
        printf("Yes\n");
        if (isPrime(n - 6)) printf("%d\n", n - 6);
        else printf("%d\n", n + 6);
    } else {
        printf("No\n");
        n++;
        while (!(isPrime(n) && (isPrime(n - 6) || isPrime(n + 6)))) n++;
        printf("%d\n", n);
    }
    return 0;
}