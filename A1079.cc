#include <bits/stdc++.h>

using namespace std;

const int maxV = 100010;

vector<int> adj[maxV];
int w[maxV], cnt[maxV];
double p, r;

double res(int i) {
    fill(cnt, cnt + maxV, INT_MAX);
    queue<int> q;
    cnt[i] = 0;
    q.push(i);
    double res = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (!adj[x].size()) {
            res += p * pow(1 + r / 100.0, cnt[x]) * w[x];
        }
        for (auto &c : adj[x]) {
            if (cnt[c] == INT_MAX) {
                cnt[c] = cnt[x] + 1;
                q.push(c);
            }
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%lf%lf", &p, &r);
    int root;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if (!k) scanf("%d", &w[i]);
        else {
            while (k--) {
                int a;
                scanf("%d", &a);
                v[a]++;
                adj[i].push_back(a);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!cnt[i]) {
            root = i;
            break;
        }
    }
    printf("%.1f\n", res(root));
    return 0;
}
