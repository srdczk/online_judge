#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
};

int n, a;
vector<Node> ns;
auto main() -> int {
    // every node
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if (!i) ns.push_back(Node{a, i + 1});
        else {
            // find the first > a
            int left = 0, right = i - 1, lastPos = -1;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                if (ns[mid].x > a) {
                    lastPos = mid;
                    right = mid - 1;
                } else left = mid + 1;
            }
            if (lastPos == -1) {
                printf("%d %d\n", a - ns[ns.size() - 1].x, ns[ns.size() - 1].y);
                ns.push_back(Node{a, i + 1});
            } else {
                if (!lastPos) {
                    printf("%d %d\n", ns[0].x - a, ns[0].y);
                    ns.insert(ns.begin(), Node{a, i + 1});
                } else {
                    auto p = ns[lastPos - 1], q = ns[lastPos];
                    if (a - p.x == q.x - a) {
                        printf("%d %d\n", a - p.x, p.y);
                    } else if (a - p.x > q.x - a) {
                        printf("%d %d\n", q.x - a, q.y);
                    } else {
                        printf("%d %d\n", a - p.x, p.y);
                    }
                    ns.insert(ns.begin() + lastPos, Node{a, i + 1});
                }
            }
        }
    }
    return 0;
}