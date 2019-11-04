#include <bits/stdc++.h>

using namespace std;

const int maxS = 40010;
const int maxK = 2510;

char name[maxS][5];
vector<int> ss[maxK];

bool cmp(const int &a, const int &b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", name[i]);
        int k;
        scanf("%d", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            ss[x].push_back(i);
        }
    }
    for (int i = 1; i < m + 1; ++i) {
        printf("%d %d\n", i, ss[i].size());
        sort(ss[i].begin(), ss[i].end(), cmp);
        for (auto &c : ss[i]) {
            printf("%s\n", name[c]);
        }
    }
    return 0;
}
