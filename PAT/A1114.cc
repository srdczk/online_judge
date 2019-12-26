#include <bits/stdc++.h>

using namespace std;

const int maxV = 10010;

struct Node {
    int val, m, area;
    Node(): val(0), m(0), area(0) {}
    Node(int v, int _m, int a): val(v), m(_m), area(a) {}
};


struct Res {
    int id, cnt;
    double am, aa;
    Res(int i, int c, double m, double a): id(i), cnt(c), am(m), aa(a) {}
};

unordered_set<int> s, sp;

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
        if (fi < fj) f[fj] = fi;
        else f[fi] = fj;
    }
}

vector<Node> as;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, c, k;
        scanf("%d%d%d%d", &a, &b, &c, &k);
        if (!s.count(a)) {
            s.insert(a);
            f[a] = a;
        }
        if (b != -1 && !s.count(b)) {
            s.insert(b);
            f[b] = b;
        }
        if (c != -1 && !s.count(c)) {
            s.insert(c);
            f[c] = c;
        }
        if (b != -1) unionT(b, a);
        if (c != -1) unionT(a, c);
        while (k--) {
            int x;
            scanf("%d", &x);
            if (!s.count(x)) {
                s.insert(x);
                f[x] = x;
            }
            unionT(x, a);
        }
        int p, q;
        scanf("%d%d", &p, &q);
        as.push_back(Node(a, p, q));
    }
    vector<Node> ps(maxV);
    vector<int> cnt(maxV, 0), res;
    for (auto &c : as) {
        int fc = findFather(c.val);
        if (!cnt[fc]++) res.push_back(fc);
        ps[fc].m += c.m;
        ps[fc].area += c.area;
    }
    fill(cnt.begin(), cnt.end(), 0);
    for (auto &c : s) cnt[findFather(c)]++;
    vector<Res> rs;
    for (auto &c : res) {
        rs.push_back(Res(c, cnt[c], (double)ps[c].m / (double)cnt[c], (double)ps[c].area / (double)cnt[c]));
    }
    sort(rs.begin(), rs.end(), [](const Res &x, const Res &y) {
            if (x.aa != y.aa) return x.aa > y.aa;
            else return x.id < y.id;
         });
    printf("%d\n", rs.size());
    for (auto &c : rs) {
        printf("%04d %d %.3f %.3f\n", c.id, c.cnt, c.am, c.aa);
        //cout << c.id << " " << c.cnt << " " << c.am << " " << c.aa << endl;
    }
    return 0;
}
