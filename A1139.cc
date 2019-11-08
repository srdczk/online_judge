#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> tx, yx;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        string x, y;
        cin >> x >> y;
        if (x.size() == y.size()) {
            tx[x].insert(y);
            tx[y].insert(x);
        } else {
            yx[x].insert(y);
            yx[y].insert(x);
        }
    }
    scanf("%d", &m);
    while (m--) {
        string x, y;
        vector<pair<string, string>> res;
        cin >> x >> y;
        if (x.size() == y.size()) {
            for (auto &c : tx[x]) {
                if (c == y) continue;
                for (auto &cp : tx[y]) {
                    if (cp == x) continue;
                    if (yx[cp].count(c) || tx[cp].count(c)) {
                        res.push_back(pair<string, string>(c[0] == '-' ? c.substr(1) : c, cp[0] == '-' ? cp.substr(1) : cp));
                    }
                }
            }
        } else {
            for (auto &c : tx[x]) {
                if (c == y) continue;
                for (auto &cp : tx[y]) {
                    if (cp == x) continue;
                    if (yx[cp].count(c)) {
                        res.push_back(pair<string, string>(c[0] == '-' ? c.substr(1) : c, cp[0] == '-' ? cp.substr(1) : cp));
                    }
                }
            }
        }

        printf("%d\n", res.size());
        for (auto &c : res) {
            printf("%s %s\n", c.first.data(), c.second.data());
        }
    }
    return 0;
}
