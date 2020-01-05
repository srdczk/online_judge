#include <bits/stdc++.h>

using namespace std;

bool isMaxHeap(const vector<int> &a, int i) {
    if (i > a.size() - 1) return 1;
    // root of tree i
    // left
    int left = 2 * i + 1, right = 2 * i + 2;
    if ((left < a.size() && a[left] > a[i]) || (right < a.size() && a[right] > a[i])) return 0;
    return isMaxHeap(a, left) && isMaxHeap(a, right);
}

bool isMinHeap(const vector<int> &a, int i) {
    if (i > a.size() - 1) return 1;
    // root of tree i
    // left
    int left = 2 * i + 1, right = 2 * i + 2;
    if ((left < a.size() && a[left] < a[i]) || (right < a.size() && a[right] < a[i])) return 0;
    return isMinHeap(a, left) && isMinHeap(a, right);
}

int cnt = 0;

void dfs(const vector<int> &a, int i) {
    if (i > a.size() - 1) return;
    dfs(a, 2 * i + 1);
    dfs(a, 2 * i + 2);
    if (cnt++) printf(" ");
    printf("%d", a[i]);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(m);
    while (n--) {
        for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
        if (isMaxHeap(a, 0)) printf("Max Heap\n");
        else if (isMinHeap(a, 0)) printf("Min Heap\n");
        else printf("Not Heap\n");
        cnt = 0;
        dfs(a, 0);
        printf("\n");
    }

    return 0;
}