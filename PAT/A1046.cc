#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    scanf("%d", &n);
    vector<int> dis(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        if (!i) dis[i] = x;
        else dis[i] = x + dis[i - 1];
    }
    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        int p;
        if (a == b) printf("0\n");
        else {
            if (a == 1) p = dis[b - 2];
            else p = dis[b - 2] - dis[a - 2];
            printf("%d\n", min(p, sum - p));
        }
    }

    return 0;
}