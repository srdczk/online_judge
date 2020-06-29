#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int cnt = 0, n = 0, x, y, z;
unordered_map<int, int> um;

unordered_map<int, unordered_set<int>> us;

int f[N];

int findFather(int i) {
    int p = i;
    while (f[i] != i) i = f[i];
    while (p != i) {
        int n = f[p];
        f[p] = i;
        p = n;
    }
    return i;
}

bool isSame(int i, int j) {
    return findFather(i) == findFather(j);
}

void unionT(int i, int j) {
    int fi = findFather(i), fj = findFather(j);
    if (fi != fj) f[fi] = fj;
}

vector<pair<int, int>> e, ne;

auto main() -> int {
    int t;
    scanf("%d", &t);
    while (t--) {
        um.clear();
        for (int i = 0; i < N; ++i) f[i] = i;
        cnt = 0;
        scanf("%d", &n);
        bool can = true;
        e.clear();
        ne.clear();
        while (n--) {
            scanf("%d%d%d", &x, &y, &z);
            if (z) e.push_back({x, y});
            else ne.push_back({x, y});
            if (!um.count(x)) um[x] = cnt++;
            if (!um.count(y)) um[y] = cnt++;
        }
        
        for (auto &p : e) {
            unionT(um[p.first], um[p.second]);
        }
        for (auto &p : ne) {
            if (isSame(um[p.first], um[p.second])) {
                can = false;
                break;
            }
        }
        if (can) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}