#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int i = 0, j = a.size() - 1;
    while (i < j) {
        if (a[i] + a[j] == m) {
            printf("%d %d\n", a[i], a[j]);
            return 0;
        } else if (a[i] + a[j] > m) j--;
        else i++;
    }
    printf("No Solution\n");
    return 0;
}