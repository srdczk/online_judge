#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

struct Node {
    int x, y;
};

Node ns[N];

int res(int n) {
    sort(ns, ns + n, [](const auto &p, const auto &q) {
        if (p.x != q.x) return p.x < q.x;
        else return p.y < q.y;
    });
    if (n < 2) return n;
    int pos = 0;
    for (int i = 1; i < n; ++i) {
        int left = 0, right = pos, lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (ns[mid].y < ns[i].y) {
                left = mid + 1;
                lastPos = mid; 
            } else right = mid - 1;
        }
        ns[lastPos + 1].y = ns[i].y;
        pos = max(pos, lastPos + 1);
    }
    return pos + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &ns[i].x, &ns[i].y);
    }
    printf("%d\n", res(n));
    return 0;
}

