#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    shared_ptr<Node> left, right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};
bool res = 1;

shared_ptr<Node> build(const vector<int> &pre, int preStart, int preEnd, const vector<int> &pos, int posStart, int posEnd) {
    if (preStart > preEnd) return NULL;
    shared_ptr<Node> node = make_shared<Node>(pre[preStart]);
    if (preStart == preEnd) return node;
    if (preStart + 1 == preEnd) {
        node->left = make_shared<Node>(pre[preEnd]);
        res = 0;
        return node;
    }
    for (int i = posStart; i < posEnd; ++i) {
        if (pos[i] == pre[preStart + 1]) {
            node->left = build(pre, preStart + 1, i - posStart + preStart + 1, pos, posStart,i);
            node->right = build(pre, i - posStart + preStart + 2, preEnd, pos, i + 1, preEnd - 1);
            break;
        }
    }
    return node;
}
int cnt = 0;

void dfs(shared_ptr<Node> node) {
    if (!node) return;
    dfs(node->left);
    if (cnt++) printf(" ");
    printf("%d", node->val);
    dfs(node->right);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> pre(n), pos(n);
    for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &pos[i]);
    shared_ptr<Node> node = build(pre, 0, n - 1, pos, 0, n - 1);
    if (res) printf("Yes\n");
    else printf("No\n");
    dfs(node);
    printf("\n");
    return 0;
}