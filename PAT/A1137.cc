#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    int sum, mg, fg, hg;
    Node(string n): name(n) {
        sum = -1;
        mg = -1;
        fg = -1;
        hg = -1;
    }
};

unordered_map<string, int> sm;

int toInt(double d) {
    int c = (d * 10.0);
    if (c % 10 >= 5) return (int)d + 1;
    else return (int)d;
}

int main() {
    int a, b, c;
    char s[1024];
    scanf("%d%d%d", &a, &b, &c);
    vector<Node> ns;
    for (int i = 0; i < a; ++i) {
        int v;
        scanf("%s%d", s, &v);
        string n(s);
        if (v >= 200) {
            if (!sm.count(n)) {
                ns.push_back(Node(n));
                sm[n] = ns.size() - 1;
            }
            ns[sm[n]].sum = v;
        }
    }
    for (int i = 0; i < b; ++i) {
        int v;
        scanf("%s%d", s, &v);
        string n(s);
        if (sm.count(n)) {
            ns[sm[n]].mg = v;
        }
    }
    for (int i = 0; i < c; ++i) {
        int v;
        scanf("%s%d", s, &v);
        string n(s);
        if (sm.count(n)) {
            ns[sm[n]].fg = v;
        }

    }
    auto it = ns.begin();
    while (it != ns.end()) {
        if (it->fg >= it->mg) it->hg = it->fg;

        else {
            it->hg = toInt(it->mg * 0.4 + (it->fg == -1 ? 0 : it->fg) * 0.6);
        }
        if (it->hg < 60) it = ns.erase(it);
        else it++;
    }
    sort(ns.begin(), ns.end(), [](const Node &a, const Node &b) {
        if (a.hg != b.hg) return a.hg > b.hg;
        else return a.name < b.name;
    });
    for (auto &c : ns) {
        printf("%s %d %d %d %d\n", c.name.data(), c.sum, c.mg, c.fg, c.hg);
    }
    return 0;
}