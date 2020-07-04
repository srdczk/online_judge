#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int s[N], tt = 0, n, x;

char buff[10];

auto main() -> int {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", buff);
        if (!strcmp(buff, "push")) {
            scanf("%d", &x);
            s[tt++] = x;
        } else if (!strcmp(buff, "pop")) {
            --tt;
        } else if (!strcmp(buff, "query")) {
            printf("%d\n", s[tt - 1]);
        } else {
            if (!tt) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}