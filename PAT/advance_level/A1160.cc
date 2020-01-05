#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

struct Node {
    int n;
    string val;
    Node (int _n, string v): n(_n), val(v) {}
};

vector<Node> res;
int k, M;
string s;

vector<bool> isP(100, 1);

void init() {
    isP[0] = 0;
    isP[1] = 0;
    for (int i = 2; i < isP.size(); ++i) {
        if (!isP[i]) continue;
        for (int j = 2; j * i < isP.size(); ++j) isP[i * j] = 0;
    }

}

bool pd(const Node &node) {
    if (node.val[0] == '0') return 0;
    int g = gcd(node.n, M);
    if (g > 2 && isP[g]) return 1;
    else return 0;
}
int cnt(string s) {
    int res = 0;
    int k = stoi(s) + 1;
    for (auto &p : to_string(k)) res += p - '0';
    return res;
}

void dfs(int level, int sum) {
    if (level == k) {
        if (!sum) {
            Node node(cnt(s), s);
            if (pd(node)) res.push_back(node);
        }
        return;
    }
    if (!sum) {
        Node node(cnt(s), s);
        if (pd(node)) res.push_back(node);
        return;
    }
    for (int i = min(sum, 9); i > -1; --i) {
        s[k - 1 - level] = (char)('0' + i);
        dfs(level + 1, sum - i);
        s[k - 1 - level] = '0';
    }
}



void process(int K, int m) {
    if (K < 5 || m < 34 || m > K * 9) {
        printf("No Solution\n");
        return;
    }
    k = K;
    M = m;
    s=string(K, '0');
    res.clear();
    s[s.size() - 1] = '9';
    s[s.size() - 2] = '9';
    dfs(2, m - 18);
    if (!res.size()) printf("No Solution\n");
    else {
        sort(res.begin(), res.end(), [](const Node &a, const Node &b) {
            if (a.n != b.n) return a.n < b.n;
            else return a.val < b.val;
        });
        for (auto &c : res) printf("%d %s\n", c.n, c.val.data());
    }
}

void process2(int K, int m) {
    if (m > K * 9) {
        printf("No Solution\n");
        return;
    }
    k = K;
    M = m;
    s=string(K, '0');
    res.clear();
    dfs(0, m);
    if (!res.size()) printf("No Solution\n");
    else {
        sort(res.begin(), res.end(), [](const Node &a, const Node &b) {
            if (a.n != b.n) return a.n < b.n;
            else return a.val < b.val;
        });
        for (auto &c : res) printf("%d %s\n", c.n, c.val.data());
    }
}

int main() {
    init();
    int N, K, m;
    scanf("%d", &N);
    if (N < 5) {
        for (int i = 1; i < N + 1; ++i) {
            scanf("%d%d", &K, &m);
            printf("Case %d\n", i);
            process2(K, m);
        }
    } else {
        for (int i = 1; i < N + 1; ++i) {
            scanf("%d%d", &K, &m);
            printf("Case %d\n", i);
            process(K, m);
        }
    }

    return 0;
}