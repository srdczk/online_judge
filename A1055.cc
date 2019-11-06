#include <bits/stdc++.h>

using namespace std;

const int maxV = 100010;
int m, n;
struct Node {
    char name[10];
    int age, sum;
};

Node ns[maxV];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", ns[i].name, &ns[i].age, &ns[i].sum);
    }
    sort(ns, ns + n, [](const Node &p, const Node &q) {
        if (p.sum != q.sum) return p.sum > q.sum;
        else if (p.age != q.age) return p.age < q.age;
        else return strcmp(p.name, q.name) < 0;
    });
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        printf("Case #%d:\n", i + 1);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (ns[j].age >= y && ns[j].age <= z) {
                printf("%s %d %d\n", ns[j].name, ns[j].age, ns[j].sum);
                if (cnt++ == x - 1) break;
            }
        }
        if (!cnt) printf("None\n");
    }
    return 0;
}