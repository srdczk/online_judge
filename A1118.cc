#include <bits/stdc++.h>

using namespace std;
const int maxV= 10010;

int f[maxV];

unordered_set<int> s;

int findFather(int i) {
    stack<int> s;
    while (f[i] != i) {
        s.push(i);
        i = f[i];
    }
    while (!s.empty()) {
        f[s.top()] = i;
        s.pop();
    }
    return i;
}

bool isSame(int i, int j) {
    return findFather(i) == findFather(j);
}

void unionT(int i, int j) {
    int fi = findFather(i);
    int fj = findFather(j);
    if (fi != fj) f[fi] = fj;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int k;
        scanf("%d", &k);
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            scanf("%d", &a[i]);
            if (!s.count(a[i])) {
                s.insert(a[i]);
                f[a[i]] = a[i];
            }
            if (i) unionT(a[i], a[i - 1]);
        }
    }
    vector<int> cnt(maxV, 0);
    int res = 0;
    for (auto &c : s) {
        if (!cnt[findFather(c)]++) res++;
    }
    printf("%d %d\n", res, s.size());
    int k;
    scanf("%d", &k);
    while (k--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (isSame(a, b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
