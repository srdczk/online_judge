#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    double y;
};

bool isZero(double d) {
    return abs(d) <= 1e-6;
}

vector<Node> add(const vector<Node> &a, const vector<Node> &b) {
    vector<Node> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i].x == b[j].x) {
            int x = a[i].x;
            double ay = a[i++].y, by = b[j++].y;
            if (!isZero(ay + by)) res.push_back(Node{x, ay + by});
        } else if (a[i].x > b[j].x) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i < a.size()) {
        res.push_back(a[i++]);
    }
    while (j < b.size()) {
        res.push_back(b[j++]);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<Node> a(n);
    for (int i = 0; i < n; ++i) scanf("%d%lf", &a[i].x, &a[i].y);
    scanf("%d", &n);
    vector<Node> b(n);
    for (int i = 0; i < n; ++i) scanf("%d%lf", &b[i].x, &b[i].y);
    vector<Node> res = add(a, b);
    printf("%d", res.size());
    for (auto &c : res) {
        printf(" %d %.1f", c.x, c.y);
    }
    printf("\n");
    return 0;
}