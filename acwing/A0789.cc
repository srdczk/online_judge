#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], n, k, c;

int first(int target) {
    int left = 0, right = n - 1, lastPos = -1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (a[mid] >= target) {
            right = mid - 1;
            if (a[mid] == target) lastPos = mid;
        } else left = mid + 1;
    }
    return lastPos;
}

int last(int target) {
    int left = 0, right = n - 1, lastPos = -1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (a[mid] <= target) {
            left = mid + 1;
            if (a[mid] == target) lastPos = mid;
        } else right = mid - 1;
    }
    return lastPos;
}

auto main() -> int {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    while (k--) {
        scanf("%d", &c);
        printf("%d %d\n", first(c), last(c));
    }
    return 0;
}