#include <bits/stdc++.h>

using namespace std;

int res(vector<int> &a) {
    int k = 1;
    int cnt = 0;
    while (k < a.size()) {
        if (!a[0]) {
            while (k < a.size() && a[k] == k) k++;
            if (k == a.size()) break;
            else swap(a[0], a[k]);
            cnt++;
        } else {
            swap(a[0], a[a[0]]);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("%d\n", res(a));
    return 0;
}
