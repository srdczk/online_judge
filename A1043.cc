#include <bits/stdc++.h>

using namespace std;

// 单调栈 判断是否是 BST or MBST
bool isBST(const vector<int> &a) {
    stack<int> s;
    int minV = INT_MIN;
    for (auto &c : a) {
        if (c < minV) return 0;
        while (!s.empty() && c > s.top()) {
            minV = s.top();
            s.pop();
        }
        s.push(c);
    }
    return 1;
}
bool isMBST(const vector<int> &a) {
    stack<int> s;
    int maxV = INT_MAX;
    for (auto &c : a) {
        if (c > maxV) return 0;
        while (!s.empty() && c < s.top()) {
            maxV = s.top();
            s.pop();
        }
        s.push(c);
    }
    return 1;
}
int cnt = 0;
void printX(const vector<int> &pre, int preStart, int preEnd, const vector<int> &in, int inStart, int inEnd) {
    if (preStart > preEnd) return;
    for (int i = inStart; i < inEnd + 1; ++i) {
        if (in[i] == pre[preStart]) {
            printX(pre, preStart + 1, i - inStart + preStart, in, inStart, i - 1);
            printX(pre, i - inStart + preStart + 1, preEnd, in, i + 1, inEnd);
            if (cnt++) printf(" ");
            printf("%d", in[i]);
            break;
        }
    }
}
void printY(const vector<int> &pre, int preStart, int preEnd, const vector<int> &in, int inStart, int inEnd) {
    if (preStart > preEnd) return;
    for (int i = inEnd; i > inStart - 1; --i) {
        if (in[i] == pre[preStart]) {
            printY(pre, preStart + 1, i - inStart + preStart, in, inStart, i - 1);
            printY(pre, i - inStart + preStart + 1, preEnd, in, i + 1, inEnd);
            if (cnt++) printf(" ");
            printf("%d", in[i]);
            break;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (isBST(a)) {
        printf("YES\n");
        vector<int> b(a);
        sort(b.begin(), b.end());
        printX(a, 0, n - 1, b, 0, n - 1);
        printf("\n");
    } else if (isMBST(a)) {
        printf("YES\n");
        vector<int> b(a);
        sort(b.begin(), b.end(), greater<int>());
        printY(a, 0, n - 1, b, 0, n - 1);
        printf("\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
