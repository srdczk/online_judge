#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int> &a, int index, int size) {
    int left = 2 * index + 1;
    while (left < size) {
        int smallest = left + 1 < size && a[left + 1] < a[left] ? left + 1 : left;
        smallest = a[index] < a[smallest] ? index : smallest;
        if (smallest == index) break;
        swap(a[index], a[smallest]);
        index = smallest;
        left = 2 * index + 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = (a.size() - 1) / 2; i > -1; --i) {
        heapify(a, i, a.size());
    }
    int res = 1;
    vector<bool> cnt(100010, 0);
    int size = a.size();
    if (a[0] > 0) {
        if (a[0] == 1) {
            cnt[1] = 1;
            res = 2;
        }
        else if (!cnt[a[0] - 1]) {
            printf("%d\n", res);
            return 0;
        } else {
            cnt[a[0]] = 1;
            res = a[0] + 1;
        }
    }
    swap(a[0], a[--size]);
    while (size > 0) {
        heapify(a, 0, size);
        if (a[0] > 0) {
            if (a[0] == 1) {
                cnt[1] = 1;
                res = 2;
            }
            else if (!cnt[a[0] - 1]) {
                printf("%d\n", res);
                return 0;
            } else {
                cnt[a[0]] = 1;
                res = a[0] + 1;
            }
        }
        swap(a[0], a[--size]);
    }

    printf("%d\n", res);

    return 0;
}
