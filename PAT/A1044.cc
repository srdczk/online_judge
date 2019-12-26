#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, sum = 0, x = INT_MAX;
    scanf("%d%d", &n, &m);
    vector<int> a(n), res;
    bool pd = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        while (sum >= m) {
            if (sum == m) {
                pd = 1;
                printf("%d-%d\n", j + 1, i + 1);
            } else if (sum - m <= x) {
                if (sum - m < x) {
                    res.clear();
                    x = sum - m;
                }
                res.push_back(j + 1);
                res.push_back(i + 1);
            }
            sum -= a[j++];
        }
    }
    if (!pd) {
        for (int i = 0; i < res.size(); i += 2) {
            printf("%d-%d\n", res[i], res[i + 1]);
        }
    }
    return 0;
}
