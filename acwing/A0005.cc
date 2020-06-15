#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010, maxV = 2010;

int N, V, v, w, s, dp[maxV];

struct Node {
    int v, w;
};

int main() {
    fill(dp, dp + maxV, 0);
    vector<Node> ns;
    scanf("%d%d", &N, &V);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &v, &w, &s);
        int k = 1;
        while (s) {
            if (s >= k) {
                ns.push_back(Node{k * v, k * w});
                s -= k;
                k *= 2;
            } else {
                ns.push_back(Node{s * v, s * w});
                s = 0;
            }
        }
    }
    for (auto &node : ns) {
        for (int j = V; j >= node.v; --j) {
            dp[j] = max(dp[j], dp[j - node.v] + node.w);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}