#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char a[N], b[N];
int n, m, i = 0;
char res[N];

void add() {
    int l = 0;
    while (n && m) {
        int p = a[--n] - '0', q = b[--m] - '0';
        if (p + q + l > 9) {
            res[i++] = (char)(p + q + l - 10 + '0');
            l = 1;
        } else {
            res[i++] = (char)(p + q + l + '0');
            l = 0;
        }
    }
    while (n) {
        int p = a[--n] - '0';
        if (p + l > 9) {
            res[i++] = (char)(p + l - 10 + '0');
            l = 1;
        } else {
            res[i++] = (char)(p + l + '0');
            l = 0;
        }
    }
    while (m) {
        int p = a[--m] - '0';
        if (p + l > 9) {
            res[i++] = (char)(p + l - 10 + '0');
            l = 1;
        } else {
            res[i++] = (char)(p + l + '0');
            l = 0;
        }
    }
    if (l) res[i++] = '1';
}


auto main() -> int {
    scanf("%s%s", a, b);
    n = strlen(a);
    m = strlen(b);
    add();
    while (i) printf("%c", res[--i]);
    printf("\n");
    return 0;
}