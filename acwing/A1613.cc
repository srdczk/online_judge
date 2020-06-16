#include <bits/stdc++.h>

using namespace std;

const int N = 9;
int a[N][N], hashX[N][N], hashY[N][N], hashZ[N][N];

bool dfs() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] == -1) {
                for (int k = 0; k < N; ++k) {
                    if (!hashX[i][k] && !hashY[j][k] && !hashZ[(i / 3) * 3 + j / 3][k]) {
                        a[i][j] = k + 1;
                        hashX[i][k]++;
                        hashY[j][k]++;
                        hashZ[(i / 3) * 3 + j / 3][k]++;
                        if (dfs()) return true;
                        a[i][j] = -1;
                        hashX[i][k]--;
                        hashY[j][k]--;
                        hashZ[(i / 3) * 3 + j / 3][k]--;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

auto main() -> int {
    fill(*a, *a + N * N, -1);
    fill(*hashX, *hashX + N * N, 0);
    fill(*hashY, *hashY + N * N, 0);
    fill(*hashZ, *hashZ + N * N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c = getchar();
            if (c != '.') {
                a[i][j] = c - '0';
                hashX[i][c - '0' - 1]++;
                hashY[j][c - '0' - 1]++;
                hashZ[(i / 3) * 3 + j / 3][c - '0' - 1]++;
            }
        }
        getchar();
    }
    dfs();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}