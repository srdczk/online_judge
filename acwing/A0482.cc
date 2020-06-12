#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N], b[N], dpA[N], dpB[N];

void res(int n) {
    dpA[0] = 0;
    dpB[n - 1] = 0;
    int posA = 0, posB = 0;
    for (int i = 1; i < n; ++i) {
        int left = 0, right = posA, lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (a[mid] < a[i]) {
                left = mid + 1;
                lastPos = mid;
            } else right = mid - 1;
        }
        a[lastPos + 1] = a[i];
        posA = max(posA, lastPos + 1);
        left = 0; right = posB; lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (b[mid] < b[i]) {
                left = mid + 1;
                lastPos = mid;
            } else right = mid - 1;
        }
        b[lastPos + 1] = b[i];
        posB = max(posB, lastPos + 1);
        dpA[i] = posA;
        dpB[n - 1 - i] = posB;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[n - 1 - i] = a[i];
    }
    res(n);
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res = max(dpA[i] + dpB[i] + 1, res);
    }
    printf("%d\n", n - res);
    return 0;
}