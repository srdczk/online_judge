#include <bits/stdc++.h>

using namespace std;
const int BUFSIZE = 1024;
unordered_map<string, set<int>> sm;

int main() {
    int n, m;
    char s[BUFSIZE];
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        while (b--) {
            scanf("%s", s);
            sm[string(s)].insert(a);
        }
    }
    while (n--) {
        scanf("%s", s);
        string sp(s);
        set<int> p = sm[sp];
        printf("%s %d", s, p.size());
        for (auto &c : p) printf(" %d", c);
        printf("\n");
    }
    return 0;
}
