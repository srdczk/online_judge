#include <bits/stdc++.h>

using namespace std;
const int maxV = 100010;
struct Node {
    int addr;
    int val;
    int next;
};
Node ns[maxV];
int main() {
    int start, n, k;
    scanf("%d%d%d", &start, &n, &k);
    while (n--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ns[a] = Node{a, b, c};
    }
    vector<Node> a;
    while (start != -1) {
        a.push_back(ns[start]);
        start = ns[start].next;
    }
    for (int i = 0; i < a.size(); i += k) {
        if (i + k < a.size() + 1) reverse(a.begin() + i, a.begin() + i + k);
    }
    for (int i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1) printf("%05d %d -1\n", a[i].addr, a[i].val);
        else printf("%05d %d %05d\n", a[i].addr, a[i].val, a[i + 1].addr);
    }
    return 0;
}
