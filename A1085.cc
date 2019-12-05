#include <bits/stdc++.h>

using namespace std;

int main() {
    long n, m;
    scanf("%ld%ld", &n, &m);
    vector<long> a(n);
    for (int i = 0; i < n; ++i) scanf("%ld", &a[i]);
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, (int)(upper_bound(a.begin(), a.end(), m * a[i]) - a.begin() - i));
    }
    printf("%d\n", res);
    return 0;
}
