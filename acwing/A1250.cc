#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int x[N][N], y[N][N], n, m;

void findFather(int p, int q, int &fx, int &fy) {
    int bp = p, bq = q;
    while (x[p][q] != p || y[p][q] != q) {
        int tmpP = p, tmpQ = q;
        p = x[tmpP][tmpQ];
        q = y[tmpP][tmpQ];
    }
    fx = p;
    fy = q;
    while (bp != p || bq != q) {
        int np = x[bp][bq], nq = y[bp][bq];
        x[bp][bq] = p;
        y[bp][bq] = q;
        bp = np;
        bq = nq;
    }
}

bool isSame(int i, int j, int p, int q) {
    int fi, fj, fp, fq;
    findFather(i, j, fi, fj);
    findFather(p, q, fp, fq);
    return fi == fp && fj == fq;
}

void unionT(int i, int j, int p, int q) {
    int fi, fj, fp, fq;
    findFather(i, j, fi, fj);
    findFather(p, q, fp, fq);
    if (fi != fp || fj != fq) {
        x[fi][fj] = fp;
        y[fi][fj] = fq;
    }
}

auto main() -> int {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            x[i][j] = i;
            y[i][j] = j;
        }
    }
    scanf("%d%d", &n, &m);
    for (int l = 0; l < m; ++l) {
        int i, j;
        char s[10];
        scanf("%d %d %s", &i, &j, s);
        int p, q;
        if (s[0] == 'D') {
            p = i + 1, q = j;
            
        } else {
            p = i, q = j + 1;
        }
        if (isSame(i, j, p, q)) {
            printf("%d\n", l + 1);
            return 0;
        } else unionT(i, j, p, q);
    }
    printf("draw\n");
    return 0;
}