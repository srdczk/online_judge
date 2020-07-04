#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

PII a[N];
int n;

auto main() -> int {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n, [](const auto &x, const auto &y) {
        if (x.first != y.first) return x.first < y.first;
        else return x.second < y.second;
    });
    int cnt = 0, b = INT_MIN, e = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (a[i].first > e) {
            b = a[i].first;
            e = a[i].second;
            cnt++;
        } else {
            e = max(a[i].second, e);
        }
    }
    printf("%d\n", cnt);
    return 0;
}