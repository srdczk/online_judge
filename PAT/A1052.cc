#include <bits/stdc++.h>

using namespace std;
const int maxV = 100000;
struct Node {
    int addr;
    int val;
    int next;
};
Node ns[maxV];
int main() {
    int n, start;
    scanf("%d%d", &n, &start);
    while (n--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ns[a] = Node{a, b, c};
    }
    vector<Node> a;
    if (start == -1) {
        printf("0 -1\n");
        return 0;
    }
    while (start != -1) {
        a.push_back(ns[start]);
        start = ns[start].next;
    }
    sort(a.begin(), a.end(), [](const Node &x, const Node &y) { return x.val < y.val; } );
    printf("%d %05d\n", a.size(), a[0].addr);
    for (int i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1) printf("%05d %d -1\n", a[i].addr, a[i].val);
        else printf("%05d %d %05d\n", a[i].addr, a[i].val, a[i + 1].addr);
    }
    return 0;
}
