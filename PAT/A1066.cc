#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};

int height(Node *node) {
    if (!node) return 0;
    return max(height(node->left), height(node->right)) + 1;
}

Node *RR(Node *node) {
    Node *right = node->right;
    Node *left = right->left;
    right->left = node;
    node->right = left;
    return right;
}

Node *LL(Node *node) {
    Node *left = node->left;
    node->left = left->right;
    left->right = node;
    return left;
}

Node *LR(Node *node) {
    node->left = RR(node->left);
    return LL(node);
}

Node *RL(Node *node) {
    node->right = LL(node->right);
    return RR(node);
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
int main() {
    int n;
    scanf("%d", &n);
    Node *node = NULL;
    while (n--) {
        int x;
        scanf("%d", &x);
        node = insert(node, x);
    }
    printf("%d\n", node->val);
    return 0;
}