#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
char a[N][N];
int h[N][N];
auto main() -> int {
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = getchar();
            getchar();
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == 'R') h[i][j] = 0;
            else if (!i) h[i][j] = 1;
            else h[i][j] = h[i - 1][j] + 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int leftMin[N], rightMin[N];
        leftMin[0] = -1;
        for (int j = 1; j < m; ++j) {
            int k = j - 1;
            while (k > -1 && h[i][k] >= h[i][j]) k = leftMin[k];
            leftMin[j] = k;
        }
        rightMin[m - 1] = m;
        for (int j = m - 2; j > -1; --j) {
            int k = j + 1;
            while (k < m && h[i][k] >= h[i][j]) k = rightMin[k];
            rightMin[j] = k;
        }
        for (int j = 0; j < m; ++j) {
            res = max(res, (rightMin[j] - leftMin[j] - 1) * h[i][j]);
        }
    }
    printf("%d\n", res * 3);
    return 0;
}