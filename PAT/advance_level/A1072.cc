#include <bits/stdc++.h>

using namespace std;
const int maxV = 1100;
struct Node {
    int v, dis;
};
int n, m, k, ds;
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.dis > b.dis;
    }
};
priority_queue<Node, vector<Node>, cmp> q;
int res = INT_MIN, x = -1;
int sum = 0;
int d[maxV];
vector<Node> adj[maxV];
void dij(int i) {
    q = priority_queue<Node, vector<Node>, cmp>();
    int dis = INT_MAX;
    fill(d, d + maxV, INT_MAX);
    q.push(Node{i, 0});
    d[i] = 0;
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        for (auto &c : adj[node.v]) {
            if (d[c.v] > node.dis + c.dis) {
                d[c.v] = node.dis + c.dis;
                q.push(Node{c.v, d[c.v]});
            }
        }
    }
    int hSum = 0;
    for (int j = m; j < n + m; ++j) {
        dis = min(dis, d[j]);
        if (d[j] > ds) return;
        hSum += d[j];
    }
    if (dis > res) {
        res = dis;
        x = i;
        sum = hSum;
    } else if (dis == res) {
        if (hSum < sum) {
            sum = hSum;
            x = i;
        }
    }
}

double process(double p) {
    int k = p * 100;
    if (k % 10 >= 5) return ((int)(p * 10) + 1) / 10.0;
    else return ((int)(p * 10)) / 10.0;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    char a[10], b[10];
    while (k--) {
        int p;
        scanf("%s%s%d", a, b, &p);
        int px, py;
        if (a[0] == 'G') px = atoi(a + 1) - 1;
        else px = atoi(a) - 1 + m;
        if (b[0] == 'G') py = atoi(b + 1) - 1;
        else py = atoi(b) - 1 + m;
        adj[px].push_back(Node{py, p});
        adj[py].push_back(Node{px, p});
    }
    for (int i = 0; i < m; ++i) {
        dij(i);
    }
    if (x == -1) printf("No Solution\n");
    else {
        printf("G%d\n", x + 1);
        printf("%.1f %.1f\n", (double)res, process((double)sum / n));
    }
    return 0;
}
