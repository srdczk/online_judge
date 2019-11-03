#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    vector<int> a;
    while (n--) {
        int x;
        scanf("%d", &x);
        m[x]++;
        if (a.size()) {
            printf("%d:", x);
            for (auto &c : a) printf(" %d", c);
            printf("\n");
        }
        auto it = find(a.begin(), a.end(), x);
        if (it != a.end()) a.erase(it);
        a.push_back(x);
        int i = a.size() - 2;
        while (i > -1 && (m[a[i]] <= m[x])) {
            if (m[a[i]] == m[x] && a[i] < x) break;
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = x;
        if (a.size() == s + 1) a.pop_back();
    }
    return 0;
}
