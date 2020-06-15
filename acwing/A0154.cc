#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int a[N], aMax[N], aMin[N], n, k;

int main() {
    scanf("%d%d", &n, &k);
    deque<int> qMax, qMin;
    for (int i = 0, j = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        while (!qMax.empty() && a[i] >= a[qMax.back()]) qMax.pop_back();
        qMax.push_back(i);
        while (!qMin.empty() && a[i] <= a[qMin.back()]) qMin.pop_back();
        qMin.push_back(i);
        if (qMax.front() == i - k) qMax.pop_front();
        if (qMin.front() == i - k) qMin.pop_front();
        if (i >= k - 1) {
            aMax[j] = a[qMax.front()];
            aMin[j++] = a[qMin.front()];
        }
    }
    for (int i = 0; i < n - k + 1; ++i) {
        if (i) printf(" ");
        printf("%d", aMin[i]);
    }
    printf("\n");
    for (int i = 0; i < n - k + 1; ++i) {
        if (i) printf(" ");
        printf("%d", aMax[i]);
    }
    printf("\n");
    return 0;
}