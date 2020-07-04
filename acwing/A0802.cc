#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int a[N], s[N], n, m, x, y;

vector<int> alls;
vector<PII> add;
vector<PII> calls;

vector<int>::iterator unique(vector<int> &a) {
    int i = 1, j = 1;
    while (j < a.size()) {
        if (a[j] != a[j - 1]) a[i++] = a[j];
        j++;
    }
    return a.begin() + i;
}

int find(int x) {
    int left = 0, right = alls.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (alls[mid] == x) return mid;
        else if (alls[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

auto main() -> int {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        add.push_back({x, y});
        alls.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        calls.push_back({x, y});
        alls.push_back(x);
        alls.push_back(y);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls), alls.end());
    for (auto &it : add) {
        a[find(it.first)] += it.second;
    }
    for (int i = 0; i < alls.size(); ++i) {
        if (!i) s[i] = a[i];
        else s[i] = s[i - 1] + a[i];
    }
    for (auto &it : calls) {
        int r = find(it.second), l = find(it.first);
        if (!l) printf("%d\n", s[r]);
        else printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}