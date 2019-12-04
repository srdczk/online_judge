#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k = 0, p = 0;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    stack<int> s;
    while (k < n || !s.empty()) {
        if (k < n) {
            s.push(k);
            k = 2 * k + 1;
        } else {
            k = s.top();
            b[k] = a[p++];
            s.pop();
            k = 2 * k + 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
