#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;

vector<bool> a(maxV, 1);

void init() {
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < maxV; ++i) {
        if (!a[i]) continue;
        for (int j = 2; j * i <= maxV; ++j) {
            a[i * j] = 0;
        }
    }
}

int findMin(int n) {
    while (!a[n]) n++;
    return n;
}

int main() {
    init();
    int m, n, cnt = 0;
    scanf("%d%d", &m, &n);
    m = findMin(m);
    vector<int> h(m, -1);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (cnt++) printf(" ");
        bool pd = 0;
        int p = 0;
        if (h[x % m] == -1) {
            h[x % m] = x;
            printf("%d", x % m);
        } else {
            int p = 1;
            bool pd = 0;
            while (p < m) {
                if (h[(x % m + p * p) % m] == -1) {
                    h[(x % m + p * p) % m] = x;
                    pd = 1;
                    break;
                }
                p++;
            }
            if (!pd) printf("-");
            else printf("%d", (x % m + p * p) % m);
        }
    }
    printf("\n");
    return 0;
}
