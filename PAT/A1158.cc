#include <bits/stdc++.h>

using namespace std;
const int maxV = 1010;
int K, N, M;

vector<vector<int>> G(maxV, vector<int>(maxV, 0));

map<int, set<int>> res;

int f[maxV];

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

void unionT(int i, int j) {
    int fi = findFather(i);
    int fj = findFather(j);
    if (fi != fj) {
        if (fi  < fj) f[fj] = fi;
        else f[fi] = fj;
    }
}

int main() {
    scanf("%d%d%d", &K, &N, &M);
    while (M--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        G[a][b] += c;
    }
    vector<int> heads;
    for (int i = 1; i < N + 1; ++i) {
        int cntCall = 0, back = 0;
        for (int j = 1; j < N + 1; ++j) {
            if (j == i) continue;
            if (G[i][j] && G[i][j] < 6) {
                cntCall++;
                if (G[j][i]) back++;
            }
        }
        // 若果 超过 个 并且返回的不超过0.2
        if (cntCall > K && back <= (0.2 * cntCall)) {
            heads.push_back(i);
            f[i] = i;
        }
    }
    if (!heads.size()) printf("None\n");
    else {
        for (int i = 0; i < heads.size(); ++i) {
            for (int j = i + 1; j < heads.size(); ++j) {
                if (G[heads[i]][heads[j]]&& G[heads[j]][heads[i]]) {
                    unionT(heads[i], heads[j]);
                }
            }
        }
        for (auto &c : heads) {
            res[findFather(c)].insert(c);
        }
        for (auto &c : res) {
            int cnt = 0;
            for (auto &p : c.second) {
                if (cnt++) printf(" ");
                printf("%d", p);
            }
            printf("\n");
        }
    }
    return 0;
}