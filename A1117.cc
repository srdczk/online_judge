#include <bits/stdc++.h>

using namespace std;

int cnt(int t, const vector<int> &a) {
    int ans = 0;
    for (auto &c : a) {
        if (c > t) ans++;
    }
    return ans;
}

int res(const vector<int> &a) {
    int left = 1, right = a.size(), lastPos = -1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (cnt(mid, a) >= mid) {
            lastPos = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    return lastPos;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    cout << res(a) << endl;
    return 0;
}
