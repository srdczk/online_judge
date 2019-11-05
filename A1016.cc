#include <bits/stdc++.h>

using namespace std;

struct Time {
    int h, m, s;
    bool x;
    Time() {}
    Time(int h, int m, int s, bool x) : h(h), m(m), s(s), x(x) {}
};

struct Entity {
    Time begin;
    Time end;
    Entity(int b, int e) {
        begin = Time(b / (24 * 60), (b % (24 * 60)) / 60, b % 60, 1);
        end = Time(e / (24 * 60), (e % (24 * 60)) / 60, e % 60, 0);
    }
    Entity(const Time &b, const Time &e) {
        begin = Time(b.h, b.m, b.s, b.x);
        end = Time(e.h, e.m, e.s, e.x);
    }
};

struct Node {
    string name;
    int month;
    vector<Time> ts;
    vector<Entity> es;
    Node(string n, int m): name(n), month(m) {}
};

bool cmpT(const Time &a, const Time &b) {
    return a.h * 24 * 60 + a.m * 60 + a.s < b.h * 24 * 60 + b.m * 60 + b.s;
}

bool cmpN(const Node &a, const Node &b) {
    if (a.name != b.name) return a.name < b.name;
    else return a.month < b.month;
}

int sub(const Time &a, const Time &b) {
    return b.h * 24 * 60 + b.m * 60 + b.s - a.h * 24 * 60 - a.m * 60 - a.s;
}


unordered_map<string, int> sm;

int cs[24];

int sumCount(const Time &a, const Time &b) {
    if (a.h == b.h) {
        if (a.m == b.m) {
            return sub(a, b) * cs[a.m];
        } else if (b.m == a.m + 1) {
            return (60 - a.s) * cs[a.m] + b.s * cs[b.m];
        } else {
            int res = (60 - a.s) * cs[a.m] + b.s * cs[b.m];
            int p = a.m + 1;
            while (p < b.m) {
                res += 60 * cs[p];
                p++;
            }
            return res;
        }
    } else {
        Time t(b.h, a.m, a.s, 0);
        int res = accumulate(cs, cs + 24, 0) * 60 * (b.h - a.h);
        if (cmpT(t, b)) return res + sumCount(t, b);
        else return res - sumCount(b, t);
    }
}

int main() {
    vector<Node> res;
    for (int i = 0; i < 24; ++i) scanf("%d", cs + i);
    int n;
    scanf("%d", &n);
    while (n--) {
        string a, b;
        int mm, h, m, s;
        char c;
        cin >> a >> mm >> c >> h >> c >> m >> c >> s >> b;
        string sa = a + to_string(mm);
        if (!sm.count(sa)) {
            res.push_back(Node(a, mm));
            sm[sa] = res.size() - 1;
        }
        res[sm[sa]].ts.push_back(Time(h, m, s, b == "on-line" ? 1 : 0));
    }
    for (auto &c : res) {
        sort(c.ts.begin(), c.ts.end(), cmpT);
        for (int i = 1; i < c.ts.size(); ++i) {
            if (!c.ts[i].x && c.ts[i - 1].x) {
                c.es.push_back(Entity(c.ts[i - 1], c.ts[i]));
            }
        }
    }
    sort(res.begin(), res.end(), cmpN);
    for (auto &c : res) {
        if (c.es.size()) {
            printf("%s %02d\n", c.name.data(), c.month);
            int sum = 0;
            for (auto &e : c.es) {
                int s = sumCount(e.begin, e.end);
                sum += s;
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", e.begin.h, e.begin.m, e.begin.s, e.end.h, e.end.m, e.end.s, sub(e.begin, e.end), s / 100.0);
            }
            printf("Total amount: $%.2f\n", sum / 100.0);
        }
    }
    return 0;
}