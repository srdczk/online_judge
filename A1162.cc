#include <bits/stdc++.h>

using namespace std;

struct Node {
    string val;
    Node *left;
    Node *right;
    Node(char *s): val(s), left(NULL), right(NULL) {}
};

string process(Node *node) {
    if (!node) return "";
    if (!node->left && !node->right) return "(" + node->val + ")";
    else if (!node->left && node->right) {
        return "(" + node->val + process(node->right) + ")";
    } else {
        return "(" + process(node->left) + process(node->right) + node->val + ")";
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node *ns[n];
    char s[100];
    for (int i = 0; i < n; ++i) ns[i] = new Node("p");
    int root;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%s%d%d", s, &x, &y);
        ns[i]->val = s;
        if (x != -1) {
            ns[i]->left = ns[x - 1];
            cnt[x - 1]++;
        }
        if (y != -1) {
            ns[i]->right = ns[y - 1];
            cnt[y - 1]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!cnt[i]) {
            root = i;
            break;
        }
    }
    printf("%s\n", process(ns[root]).data());
    return 0;
}