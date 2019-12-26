#include <bits/stdc++.h>

using namespace std;
vector<int> res, tmp;

void dfs(int n, int i) {
    if (n % i) return;
    tmp.push_back(i);
    dfs(n / i, i + 1);
}

void ans(int n) {
    for (int i = 2; i <= (int)(sqrt(n)); ++i) {
        if (!(n  % i)) {
            tmp.clear();
            dfs(n, i);
            if (tmp.size() > res.size()) res = tmp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    ans(n);
    if (!res.size()) {
        printf("1\n");
        printf("%d\n", n);
    } else {
        printf("%d\n", res.size());
        for (int i = 0; i < res.size(); ++i) {
            if (i) printf("*");
            printf("%d", res[i]);
        }
        printf("\n");
    }

    return 0;
}
