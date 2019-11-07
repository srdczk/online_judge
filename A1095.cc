#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    int val;
    bool x;
    Node() {}
    Node(string n, int v, bool _x): name(n), val(v), x(_x) {}
};

unordered_map<string, int> sm;

int process(int x, int y, int z) {
    return z + y * 60 + x * 60 * 60;
}

int main() {
    int n, m;
    char a[1024], b[1024];
    scanf("%d%d", &n, &m);
    vector<Node> ns(n);
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        scanf("%s %d:%d:%d %s", a, &x, &y, &z, b);
        ns[i].name = a, ns[i].val = process(x, y, z), ns[i].x = !strcmp(b, "in") ? 1 : 0;
    }
    sort(ns.begin(), ns.end(), [](const Node &x, const Node &y) {
       if (x.name != y.name) return x.name < y.name;
        return x.val < y.val;
    });
    vector<int> as(24 * 60 * 60, 0);
    for (int i = 0; i < ns.size() - 1; ++i) {
        if (ns[i].name == ns[i + 1].name && ns[i].x == 1 && ns[i + 1].x == 0) {
            sm[ns[i].name] += ns[i + 1].val - ns[i].val;
            as[ns[i].val]++;
            as[ns[i + 1].val]--;
        }
    }
    int cnt = 0;
    for (int i = 0; i < as.size(); ++i) {
        cnt += as[i];
        as[i] = cnt;
    }
    while (m--) {
        int x, y, z;
        scanf("%d:%d:%d", &x, &y, &z);
        printf("%d\n", as[process(x, y, z)]);
    }
    int u = -1;
    vector<string> res;
    for (auto &it : sm) {
        if (it.second > u) {
            res.clear();
            res.push_back(it.first);
            u = it.second;
        } else if (it.second == u) res.push_back(it.first);
    }
    if (res.size() > 1) sort(res.begin(), res.end());
    for (auto &c : res) printf("%s ", c.data());
    printf("%02d:%02d:%02d\n", u / 3600, (u % 3600) / 60 , u % 60);
    return 0;
}