#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node *build(const vector<int> &in, int inStart, int inEnd, const vector<int> &pos, int posStart, int posEnd) {
    if (inStart > inEnd) return nullptr;
    Node *node = new Node(pos[posEnd]);
    for (int i = inStart; i < inEnd + 1; ++i) {
        if (in[i] == pos[posEnd]) {
            node->left = build(in, inStart, i - 1, pos, posStart, i - 1 - inStart + posStart);
            node->right = build(in, i + 1, inEnd, pos, i - inStart + posStart, posEnd - 1);
            break;
        }
    }
    return node;
}

void bfs(Node *node) {
    int cnt = 0;
    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (cnt++) printf(" ");
        printf("%d", node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> pos(n), in(n);
    for (int i = 0; i < n; ++i) scanf("%d", &pos[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    Node *node = build(in, 0, n - 1, pos, 0, n - 1);
    bfs(node);
    return 0;
}
