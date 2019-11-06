#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;
struct Node {
    string name;
    int val;
    Node(string n): name(n), val(0) {}
};

struct Res {
    string name;
    string p;
    int val;
    int sum;
    int cnt;
    Res(string n) {
        name = n;
        val = 0;
        sum = 0;
        cnt = 0;
    }
};

vector<Node> ns;

vector<int> f(maxV);
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

void unionT(int i, int j, int c) {
    int fi = findFather(i);
    int fj = findFather(j);
    if (fi != fj) {
        f[fi] = fj;
    }
}

unordered_map<string, int> sm;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char a[1024], b[1024];
    while (n--) {
        int c;
        scanf("%s%s%d", a, b, &c);
        string sa(a), sb(b);
        if (!sm.count(sa)) {
            ns.push_back(Node(sa));
            sm[sa] = ns.size() - 1;
            f[ns.size() - 1] = ns.size() - 1;
        }
        if (!sm.count(sb)) {
            ns.push_back(Node(sb));
            sm[sb] = ns.size() - 1;
            f[ns.size() - 1] = ns.size() - 1;
        }
        ns[sm[sa]].val += c;
        ns[sm[sb]].val += c;
        unionT(sm[sa], sm[sb], c);
    }
    vector<Res> rs;
    unordered_map<string, int> um;
    for (int i = 0; i < ns.size(); ++i) {
        int fi = findFather(i);
        if (!um.count(ns[fi].name)) {
            rs.push_back(Res(ns[fi].name));
            um[ns[fi].name] = rs.size() - 1;
        }
        rs[um[ns[fi].name]].cnt++;
        rs[um[ns[fi].name]].sum += ns[i].val;
        if (ns[i].val > rs[um[ns[fi].name]].val) {
            rs[um[ns[fi].name]].p = ns[i].name;
            rs[um[ns[fi].name]].val = ns[i].val;
        }
    }
    vector<Res> res;
    for (auto &c : rs) {
        if (c.cnt > 2 && c.sum > m * 2) {
            res.push_back(c);
        }
    }
    sort(res.begin(), res.end(), [](const Res &x, const Res &y) {
        return x.p < y.p;
    });
    cout << res.size() << endl;
    for (auto &c : res) cout << c.p << " " << c.cnt << endl;
    return 0;
}