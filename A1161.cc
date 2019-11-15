#include <bits/stdc++.h>

using namespace std;
const int maxV = 100010;
struct Node {
    int addr;
    int val;
    int next;
    Node() {}
    Node(int a, int v, int n): addr(a), val(v), next(n) {}
};

Node ns[maxV];

vector<Node> merge(const vector<Node> &a, const vector<Node> &b) {
    vector<Node> res;
    if (a.size() < b.size()) return merge(b, a);
    int i = 0, j = b.size() - 1;
    while (i < a.size() && j > -1) {
        res.push_back(a[i]);
        if (i + 1 < a.size()) res.push_back(a[i + 1]);
        i += 2;
        res.push_back(b[j--]);
    }
    while (i < a.size()) res.push_back(a[i++]);
    while (j > -1) res.push_back(b[j--]);
    return res;
}

int main() {
    int aStart, bStart, n;
    scanf("%d%d%d", &aStart, &bStart, &n);
    while (n--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        ns[x] = Node(x, y, z);
    }
    vector<Node> a, b;
    while (aStart != -1) {
        a.push_back(ns[aStart]);
        aStart = ns[aStart].next;
    }
    while (bStart != -1) {
        b.push_back(ns[bStart]);
        bStart = ns[bStart].next;
    }
    vector<Node> res = merge(a, b);
    for (int i = 0; i < res.size(); ++i) {
        if (i != res.size() - 1) printf("%05d %d %05d\n", res[i].addr, res[i].val, res[i + 1].addr);
        else printf("%05d %d -1\n", res[i].addr, res[i].val);
    }
    return 0;
}