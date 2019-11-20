#include <bits/stdc++.h>

using namespace std;

bool isMaxHeap(const vector<int> &a, int i) {
    if (i > a.size() - 1) return 1;
    int left = 2 * i + 1, right = 2 * i + 2;
    if ((left < a.size() && a[left] > a[i]) || (right < a.size() && a[right] > a[i])) return 0;
    return isMaxHeap(a, left) && isMaxHeap(a, right);
}

bool isMinHeap(const vector<int> &a, int i) {
    if (i > a.size() - 1) return 1;
    int left = 2 * i + 1, right = 2 * i + 2;
    if ((left < a.size() && a[left] < a[i]) || (right < a.size() && a[right] < a[i])) return 0;
    return isMinHeap(a, left) && isMinHeap(a, right);
}

void printPath(const vector<int> &a, int i) {
    int cnt = 0;
    stack<int> s;
    while (i) {
        s.push(a[i]);
        i = (i - 1) / 2;
    }
    printf("%d", a[0]);
    while (!s.empty()) {
        printf(" %d", s.top());
        s.pop();
    }
    printf("\n");
}

void dfs(const vector<int> &a, int i) {
    if (i > a.size() - 1) return;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left > a.size() - 1 && right > a.size() - 1) printPath(a, i);
    dfs(a, right);
    dfs(a, left);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    dfs(a, 0);
    if (isMaxHeap(a, 0)) printf("Max Heap\n");
    else if (isMinHeap(a, 0)) printf("Min Heap\n");
    else printf("Not Heap\n");
    return 0;
}