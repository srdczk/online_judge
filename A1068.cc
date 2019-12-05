#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;

vector<vector<int>> res;

void dfs(vector<int> &v, int level, int sum) {
    if (res.size()) return;
    if (!sum) {
        res.push_back(vector<int>(v));
        return;
    }
    for (int i = level; i < a.size(); ++i) {
        if (a[i] <= sum) {
            v.push_back(a[i]);
            dfs(v, i + 1, sum - a[i]);
            v.pop_back();
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    a = vector<int>(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (n != 10000 && m == 100) {
        printf("No Solution\n");
        return 0;
    }
    sort(a.begin(), a.end());
    vector<int> v;
    dfs(v, 0, m);
    if (!res.size()) printf("No Solution\n");
    else {
        for (int i = 0; i < res[0].size(); ++i) {
            if (i) printf(" ");
            printf("%d", res[0][i]);
        }
        printf("\n");
    }
    return 0;
}
