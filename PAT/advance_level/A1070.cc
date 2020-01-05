#include <bits/stdc++.h>

using namespace std;

struct Node {
    double a;
    double b;
    double t;
};

int main() {
    int n; double t;
    scanf("%d%lf", &n, &t);
    vector<Node> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &a[i].a);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &a[i].b);
        a[i].t = a[i].b / a[i].a;
    }
    sort(a.begin(), a.end(), [](const Node &a, const Node &b) {
            return a.t > b.t;
         });
    double ans = 0;
    for (auto &c : a) {
        if (t > c.a) {
            ans += c.b;
            t -= c.a;
        } else {
            ans += c.b * (t) / c.a;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
