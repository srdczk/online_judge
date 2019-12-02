#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> a, b, c, d;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (x > 0) a.push_back(x);
        else b.push_back(x);
    }
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (x > 0) c.push_back(x);
        else d.push_back(x);
    }
    sort(a.begin(), a.end(), [](int x, int y) { return x > y; });
    sort(b.begin(), b.end(), [](int x, int y) { return x < y; });
    sort(c.begin(), c.end(), [](int x, int y) { return x > y; });
    sort(d.begin(), d.end(), [](int x, int y) { return x < y; });
    int res = 0;
    for (int i = 0; i < min(a.size(), c.size()); ++i) {
        res += a[i] * c[i];
    }
    for (int i = 0; i < min(b.size(), d.size()); ++i) {
        res += b[i] * d[i];
    }
    printf("%d\n", res);
    return 0;
}
