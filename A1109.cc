#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    int val;
    Node() {}
    Node(const char *a, int v): name(a), val(v) {}
};

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int p = n / k;
    vector<Node> a(n);
    vector<vector<Node>> res;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].name >> a[i].val;
    }
    sort(a.begin(), a.end(), [](const Node &a, const Node &b) {
        if (a.val != b.val) return a.val < b.val;
        else return a.name < b.name;
    });
    for (int i = 0; i < k; ++i) {
        int size = i != k - 1 ? p : n - (p) * (k - 1);
        vector<Node> p(size);
        sort(a.begin() + i * (n / k), a.begin() + i * (n / k) + size, [](const Node &a, const Node &b) {
            if (a.val != b.val) return a.val > b.val;
            else return a.name < b.name;
        });
        int c = size / 2, cnt = 0, right = c, left = c - 1;
        while (cnt < size) {
            if (!(cnt % 2)) {
                if (right >= size) {
                    p[left--] = a[i * (n / k) + cnt];
                } else {
                    p[right++] = a[i * (n / k) + cnt];
                }
            } else {
                if (left < 0) p[right++] = a[i * (n / k) + cnt];
                else p[left--] = a[i * (n / k) + cnt];
            }
            cnt++;
        }
        res.insert(res.begin(), p);
    }
    for (auto &c : res) {
        for (int i = 0; i < c.size(); ++i) {
            if (i) printf(" ");
            printf("%s", c[i].name.data());
        }
        printf("\n");
    }
    return 0;
}
