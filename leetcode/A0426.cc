/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public: 
    Node *begin = nullptr, *pre = nullptr;
    void dfs(Node *node) {
        if (!node) return;
        dfs(node->left);
        if (!begin) begin = node;
        node->left = pre;
        if (pre) pre->right = node;
        pre = node;
        dfs(node->right);
    }
    Node* treeToDoublyList(Node* root) {
        dfs(root);
        if (begin) {
            begin->left = pre;
            pre->right = begin;
        }
        return begin;
    }
};