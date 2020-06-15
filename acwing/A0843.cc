#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, q[N];

void dfs(int i) {
    if (i == n) {
        // print and return;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (q[j] == k) printf("Q");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int j = 0; j < n; ++j) {
        int k;
        for (k = 0; k < i; ++k) {
            if (q[k] == j || abs(j - q[k]) == abs(i - k)) break;
        }
        if (k >= i) {
            q[i] = j;
            dfs(i + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}