#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int N = 300010;

char str[N];
ULL p[N], h[N];
int s[N];
int n;

ULL base = 131;

ULL get(int i, int size) {
    if (!i) {
        return h[size - 1];
    } else {
        return h[size - 1 + i] - h[i - 1] * p[size];
    }
}

int maxCommon(int i, int j) {
    int left = 1, right = min(n - i, n - j), lastPos = -1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (get(i, mid) == get(j, mid)) {
            left = mid + 1;
            lastPos = mid;
        } else right = mid - 1;
    }
    return lastPos;
}

bool cmp(int i, int j) {
    int common = maxCommon(i, j);
    if (common == -1) return str[i] < str[j];
    else if (common == n - i) return true;
    else if (common == n - j) return false;
    return str[i + common] < str[j + common];
}

auto main() -> int {
    scanf("%s", str);
    n = strlen(str);
    p[0] = 1;
    h[0] = str[0];
    s[0] = 0;
    for (int i = 1; i < n; ++i) {
        h[i] = h[i - 1] * (ULL)base + str[i];
        p[i] = p[i - 1] * (ULL)base;
        s[i] = i;
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", s[i]);
    }
    printf("\n0");
    for (int i = 1; i < n; ++i) {
        int p;
        printf(" %d", (p = maxCommon(s[i], s[i - 1])) == -1 ? 0 : p);
    }
    printf("\n");
    return 0;
}