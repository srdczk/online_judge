#include <bits/stdc++.h>

using namespace std;

// store in rodata
const int maxN = 55;

int res, N, endD, endU;

int down[maxN], up[maxN];
int a[maxN];


void insertDown(int p, int &x, int &y) {
    if (!endD || p >= down[endD - 1]) {
        y = -1;
        x = 0;
        down[endD++] = p;
    } else {
        int left = 0, right = endD - 1, lastPos = -1;
        while (left <= right) {
           int mid = left + ((right - left) >> 1);
           if (down[mid] > p) {
               right = mid - 1;
               lastPos = mid;
           } else left = mid + 1;
        }
        y = down[lastPos];
        x = lastPos;
        down[lastPos] = p;
    }
}

void insertUp(int p, int &x, int &y) {
    if (!endU || p <= up[endU - 1]) {
        y = -1;
        x = 0;
        up[endU++] = p;
    } else {
        int left = 0, right = endU - 1, lastPos = -1;
        while (left <= right) {
           int mid = left + ((right - left) >> 1);
           if (up[mid] < p) {
               right = mid - 1;
               lastPos = mid;
           } else left = mid + 1;
        }
        y = up[lastPos];
        x = lastPos;
        up[lastPos] = p;
    }
}

void dfs(int i) {
    if (res <= endD + endU) return;
    if (i == N) {
        res = min(res, endD + endU);
        return;
    }
    // test insert Down
    int x, y;
    insertDown(a[i], x, y);
    dfs(i + 1);
    if (y == -1) {
        --endD;
    } else {
        down[x] = y;
    }
    // pop
    
    //test insertUp
    insertUp(a[i], x, y);
    dfs(i + 1);
    if (y == -1) {
        --endU;
    } else {
        up[x] = y;
    }
}

int main() {
    while (scanf("%d", &N), N) {
        res = N;
        endD = 0;
        endU = 0;
        for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
        dfs(0);
        printf("%d\n", res);
    }
    return 0;
}