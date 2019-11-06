#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;

vector<bool> pd(maxV, 1);

void init() {
    pd[0] = 0;
    pd[1] = 0;
    for (int i = 2; i < maxV; ++i) {
        if (!pd[i]) continue;
        for (int j = 2; j * i < maxV; ++j) pd[i * j] = 0;
    }
}

int findMin(int m) {
    while (!pd[m]) m++;
    return m;
}


int main() {
    init();
    int t, n, m;
    scanf("%d%d%d", &t, &n, &m);
    t = findMin(t);
    vector<int> h(t, -1);
    unordered_map<int, int> im;
    while (n--) {
        int x;
        scanf("%d", &x);
        int p = 0;
        bool px = 0;
        while (p < t) {
            if (h[(x + p * p) % t] == -1) {
                px = 1;
                h[(x + p * p) % t] = x;
                break;
            }
            p++;
        }
        if (px) im[x] = p;
        else printf("%d cannot be inserted.\n", x);
    }
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        if (im.count(x)) sum += im[x] + 1;
        else {
            int p = 0;
            while (p < t) {
                if (h[(x + p * p) % t] == -1) {
                    break;
                }
                p++;
            }
            sum += p + 1;
        }
    }
    printf("%.1f\n", (double)sum / m);
    return 0;
}
