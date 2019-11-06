#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id, es, fs, cnt;
    deque<int> dq;
    Node() {}
    Node(int i, int e, int f): id(i), es(e), fs(f) {}
};

int main() {
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
    vector<int> as(m);
    for (int i = 0; i < m; ++i) scanf("%d", &as[i]);
    vector<Node> ns(n);
    for (int i = 0; i < n; ++i) {
        ns[i].id = i;
        scanf("%d%d", &ns[i].es, &ns[i].fs);
        for (int j = 0; j < c; ++j) {
            int x;
            scanf("%d", &x);
            ns[i].dq.push_back(x);
        }
    }
    sort(ns.begin(), ns.end(), [](const Node &a, const Node &b) {
       if (a.fs + a.es != b.es + b.fs) return a.fs + a.es > b.fs + b.es;
       else return a.es > b.es;
    });
    int ec = ns[0].es, sc = ns[0].fs + ns[0].es, cnt = 1;
    for (int i = 0; i < ns.size(); ++i) {
        if (!(ec == ns[i].es && sc == ns[i].fs + ns[i].es)) {
            ec = ns[i].es;
            sc = ns[i].fs + ns[i].es;
            cnt = i + 1;
        }
        ns[i].cnt = cnt;
    }
    vector<bool> p(n, 0);
    for (int i = 0; i < as.size(); ++i) {
        vector<int> res;
        int sum = 0, lastPos = -1;
        for (int j = 0; j < ns.size(); ++j) {
            if (p[j]) continue;
            while (ns[j].dq.size() && ns[j].dq.front() < i) ns[j].dq.pop_front();
            if (ns[j].dq.size() && ns[j].dq.front() == i) {
                if (sum < as[i]) {
                    res.push_back(ns[j].id);
                    sum++;
                    lastPos = ns[j].cnt;
                    p[j] = 1;
                } else if (lastPos == ns[j].cnt) {
                    res.push_back(ns[j].id);
                    p[j] = 1;
                } else {
                    ns[j].dq.pop_front();
                }
            }
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i) {
            if (i) printf(" ");
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}
