#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);
    vector<string> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    unordered_set<string> s;
    int i = p - 1;
    while (i < m) {
        if (!s.count(a[i])) {
            s.insert(a[i]);
            printf("%s\n", a[i].data());
            i += n;
        } else {
            while (i < m && s.count(a[i])) i++;
            if (i < m) {
                s.insert(a[i]);
                printf("%s\n", a[i].data());
                i += n;
            }
        }
    }
    if (!s.size()) printf("Keep going...\n");
    return 0;
}
