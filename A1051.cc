#include <bits/stdc++.h>

using namespace std;

bool pd(const vector<int> &a, int m) {
    stack<int> s;
    int j = 0;
    for (int i = 1; i < a.size() + 1; ++i) {
        if (s.size() == m) return 0;
        s.push(i);
        while (!s.empty() && s.top() == a[j]) {
            s.pop();
            j++;
        }
    }
    return j == a.size();
}

int main() {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    vector<int> a(n);
    while (k--) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        if (pd(a, m)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
