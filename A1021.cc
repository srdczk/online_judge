#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;

int f[maxV];

vector<int> adj[maxV];
bool vis[maxV];



int height(int root) {
    vis[root] = 1;
    int res = 0;
    for (auto &c : adj[root]) {
        if (!vis[c]) res = max(res, height(c));
    }
    return res + 1;
}

int n;

void init() {
    for (int i = 0; i < n; ++i) {
        f[i] = i;
    }
}

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
    if (fi != fj) f[fi] = fj;
}

int main() {

    scanf("%d", &n);
    vector<int> cnt(n, 0);
    init();
    int p = n;
    while (--p) {
        int a, b;
        scanf("%d%d", &a, &b);
        unionT(a - 1, b - 1);
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!cnt[findFather(i)]++) res++;
    }
    if (res != 1) {
        printf("Error: %d components\n", res);
    } else {
        vector<int> as;
        int MAX = INT_MIN;
        for (int i = 0; i < n; ++i) {
            fill(vis, vis + maxV, 0);
            int h = height(i);
            if (h > MAX) {
                MAX = h;
                as.clear();
                as.push_back(i + 1);
            } else if (h == MAX) {
                as.push_back(i + 1);
            }
        }
        for (auto &c : as) {
            printf("%d\n", c);
        }
    }
    //cout << res << endl;
    return 0;
}
