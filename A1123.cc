#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};

Node *LL(Node *node) {
    Node *left = node->left;
    node->left = left->right;
    left->right = node;
    return left;
}

Node *RR(Node *node) {
    Node *right = node->right;
    node->right = right->left;
    right->left = node;
    return right;
}

Node *LR(Node *node) {
    node->left = RR(node->left);
    return LL(node);
}
Node *RL(Node *node) {
    node->right = LL(node->right);
    return RR(node);
}
int height(Node *node) {
    if (!node) return 0;
    return max(height(node->left), height(node->right)) + 1;
}
Node *insert(Node *node, int x) {
    if (!node) return new Node(x);
    if (node->val > x) {
        node->left = insert(node->left, x);
        if (height(node->left) - height(node->right) == 2) {
            if (node->left->val > x) node = LL(node);
            else node = LR(node);
        }
    } else {
        node->right = insert(node->right, x);
        if (height(node->right) - height(node->left) == 2) {
            if (node->right->val < x) node = RR(node);
            else node = RL(node);
        }
    }
    return node;
}

bool res = 1;

vector<int> bfs(Node *node) {
    bool pd = 1;
    vector<int> a;
    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        a.push_back(node->val);
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (pd) {
            if (node->left) {
                if (!node->right) {
                    pd = 0;
                    continue;
                }
            } else {
                if (node->right) {
                    res = 0;
                    continue;
                } else {
                    pd = 0;
                    continue;
                }
            }
        } else {
            if (node->left || node->right) {
                res = 0;
                continue;
            }
        }
    }
    return a;
}

int main() {
    int n, x;
    Node *node = NULL;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        node = insert(node, x);
    }
    vector<int> a = bfs(node);
    for (int i = 0; i < a.size(); ++i) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    if (res) printf("YES\n");
    else printf("NO\n");
    return 0;
}