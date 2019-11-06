#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    int val;
    Node() {}
    Node(string n): name(n), val(0) {}

    Node(const string &name, int val) : name(name), val(val) {}
};

bool cmp(const Node &x, const Node &y) {
    if (x.val != y.val) return x.val > y.val;
    else return x.name < y.name;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Node> ns(n);
    for (int i = 0; i < n; ++i) {
        cin >> ns[i].name >> ns[i].val;
        string t = ns[i].name.substr(1, 3);
    }
    for (int i = 1; i < m + 1; ++i) {
        int x;
        string s;
        cin >> x >> s;
        vector<Node> as;
        printf("Case %d: %d %s\n", i, x, s.data());
        if (x == 1) {
            for (auto &c : ns) {
                if (c.name[0] == s[0]) as.push_back(c);
            }
        } else if (x == 2) {
            int sum = 0, cnt = 0;
            for (auto &c : ns) {
                if (c.name.substr(1, 3) == s) {
                    cnt++;
                    sum += c.val;
                }
            }
            if (!cnt) printf("NA\n");
            else printf("%d %d\n", cnt, sum);
        } else if (x == 3) {
            unordered_map<string, int> m;
            for (auto &c : ns) {
                if (c.name.substr(4, 6) == s) m[c.name.substr(1, 3)]++;
            }
            for (auto it : m) as.push_back(Node(it.first, it.second));
        }
        if ((x == 1 || x == 3)) {
            if (!as.size()) printf("NA\n");
            else {
                sort(as.begin(), as.end(), cmp);
                for (auto &c : as) printf("%s %d\n", c.name.data(), c.val);
            }
        }
    }
    return 0;
}