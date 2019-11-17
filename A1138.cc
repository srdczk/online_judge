#include <bits/stdc++.h>

using namespace std;

vector<int> a;

void dfs(const vector<int> &pre, int preStart, int preEnd, const vector<int> &in, int inStart, int inEnd) {
    if (a.size()) return;
    if (preStart > preEnd) return;
    for (int i = inStart; i < inEnd + 1; ++i) {
        if (in[i] == pre[preStart]) {
            dfs(pre, preStart + 1, i - inStart + preStart, in, inStart, i - 1);
            dfs(pre, i - inStart + preStart + 1, preEnd, in, i + 1, inEnd);
            a.push_back(pre[preStart]);
            break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> pre(n), in(n);
    for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    dfs(pre, 0, n - 1, in, 0, n - 1);
    printf("%d\n", a[0]);
    return 0;
}