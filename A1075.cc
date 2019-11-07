#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    vector<int> a;
    vector<bool> ap;
    Node(string n, int k) {
        name = n;
        a = vector<int>(k, -1);
        ap = vector<bool>(k, 0);
    }
};

int sum(const vector<int> &a) {
    int ans = 0;
    for (auto &c : a) ans += max(0, c);
    return ans;
}

vector<int> as;
int countMax(const vector<int> &a) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == as[i]) cnt++;
    }
    return cnt;
}

int countPass(const vector<int> &a) {
    int cnt = 0;
    for (auto &c : a) {
        if (c != -1) cnt++;
    }
    return cnt;
}

unordered_map<string, int> sm;
int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    vector<Node> ns;
    as = vector<int>(k);
    for (int i = 0; i < k; ++i) scanf("%d", &as[i]);
    while (m--) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (!sm.count(s)) {
            ns.push_back(Node(s, k));
            sm[s] = ns.size() - 1;
        }
        ns[sm[s]].ap[x - 1] = 1;
        ns[sm[s]].a[x - 1] = max(ns[sm[s]].a[x - 1], y);
    }
    sort(ns.begin(), ns.end(), [](const Node &x, const Node &y) {
            int p = sum(x.a), q = sum(y.a);
            if (p != q) return p > q;
            else {
                if (p == 0) {
                    int i = countPass(x.a), j = countPass(y.a);
                    if (i == 0 && j == 0) {
                        return x.name < y.name;
                    } else if (i != 0 && j == 0) {
                        return true;
                    } else if (i == 0 && j != 0) {
                        return false;
                    } else {
                        return x.name < y.name;
                    }
                } else {
                    int cx = countMax(x.a), cy = countMax(y.a);
                    if (cx != cy) return cx > cy;
                    else return x.name < y.name;
                }
            }
         });
    int x = sum(ns[0].a), cnt = 1;
    for (int i = 0; i < ns.size(); ++i) {
        if (!countPass(ns[i].a)) break;
        int sa = sum(ns[i].a);
        if (x != sa) {
            x = sa;
            cnt = i + 1;
        }
        printf("%d %s %d", cnt, ns[i].name.data(), sa);
        for (int j = 0; j < k; ++j) {
            if (ns[i].a[j] == -1) {
                if (!ns[i].ap[j]) printf(" -");
                else printf(" 0");
            } else printf(" %d", ns[i].a[j]);
        }
        printf("\n");
    }
    return 0;
}
