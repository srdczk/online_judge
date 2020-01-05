#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    bool x = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            //假设i, j二位是🐀
            vector<int> a(n, 1);
            a[i] = -1, a[j] = -1;
            vector<int> res;
            for (int k = 0; k < n; ++k) {
                if (a[abs(p[k]) - 1] * p[k] < 0) res.push_back(k);
            }
            if (res.size() == 2 && !(a[res[0]] + a[res[1]])) {
                printf("%d %d\n", i + 1, j + 1);
                x = 1;
                break;
            }
        }
        if (x) break;
    }
    if (!x) printf("No Solution\n");
    return 0;
}
