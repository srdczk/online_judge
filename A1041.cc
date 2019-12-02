#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> cnt(maxV, 0);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (auto &c : a) {
        if (cnt[c] == 1) {
            printf("%d\n", c);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}