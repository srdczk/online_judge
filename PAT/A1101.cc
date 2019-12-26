#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), res, leftMax(n, INT_MIN), rightMin(n, INT_MAX);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = a.size() - 2; i > -1; --i) {
        rightMin[i] = min(rightMin[i + 1], a[i + 1]);
    }
    if (a[0] < rightMin[0]) res.push_back(a[0]);
    for (int i = 1; i < a.size(); ++i) {
        leftMax[i] = max(leftMax[i - 1], a[i - 1]);
        if (a[i] > leftMax[i] && a[i] < rightMin[i]) {
            res.push_back(a[i]);
        }
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); ++i) {
        if (i) printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}
