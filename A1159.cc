#include <bits/stdc++.h>

using namespace std;
const int maxV = 1010;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node (int v): val(v), left(NULL), right(NULL) {}
};
Node *root;
unordered_map<int, Node *> m;
bool pd = true;
vector<int> f(maxV, -1), level(maxV, -1);

void bfs() {
    queue<Node *> q;
    q.push(root);
    level[root->val] = 0;
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        if (node->left) {
            f[node->left->val] = node->val;
            q.push(node->left);
            level[node->left->val] = level[node->val] + 1;
        }
        if (node->right) {
            f[node->right->val] = node->val;
            q.push(node->right);
            level[node->right->val] = level[node->val] + 1;
        }
        if ((node->left && !node->right) || (node->right && !node->left)) pd = 0;
    }
}

Node *build(const vector<int> &post, int postStart, int postEnd, const vector<int> &in, int inStart, int inEnd) {
    if (postStart > postEnd) return NULL;
    Node *node = new Node(post[postEnd]);
    m[post[postEnd]] = node;
    for (int i = inStart; i < inEnd + 1; ++i) {
        if (in[i] == post[postEnd]) {
            node->left = build(post, postStart, postStart + i - 1 - inStart, in, inStart, i - 1);
            node->right = build(post, postStart + i - inStart, postEnd - 1, in, i + 1, inEnd);
            break;
        }
    }
    return node;
}



vector<string> split(string s) {
    vector<string> res;
    char *as = const_cast<char *>(s.data());
    char *t;
    res.push_back(string(strtok(as, " ")));
    while ((t = strtok(NULL, " ")) != NULL) {
        res.push_back(string(t));
    }
    return res;
}

bool isRight(string p) {
    vector<string> a = split(p);
    if (a[a.size() - 1] == "root") {
        if (stoi(a[0]) == root->val) return 1;
        else return 0;
    } else if (a[a.size() - 1] == "siblings") {
        int x = stoi(a[0]), y = stoi(a[2]);
        if (m.count(x) && m.count(y) && f[x] == f[y]) return 1;
        else return 0;
    } else if (a[a.size() - 1] == "level") {
        int x = stoi(a[0]), y = stoi(a[2]);
        if (m.count(x) && m.count(y) && level[x] == level[y]) return 1;
        else return 0;
    } else if (a[a.size() - 1] == "tree") {
        return pd;
    } else if (a[a.size() - 3] == "parent") {
        int x = stoi(a[0]), y = stoi(a[5]);
        if (m.count(x) && m.count(y) && f[y] == x) return 1;
        else return 0;
    } else {
        int x = stoi(a[0]), y = stoi(a[a.size() - 1]);
        if (a[3] == "left") {
            if (m.count(x) && m.count(y) && m[y]->left && m[y]->left->val == x) {
                return 1;
            } else return 0;
        } else {
            if (m.count(x) && m.count(y) && m[y]->right && m[y]->right->val == x) {
                return 1;
            } else return 0;
        }
    }
}


int main() {
    int n, m;
    scanf("%d", &n);
    vector<int> post(n), in(n);
    for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    root = build(post, 0, n - 1, in, 0, n - 1);
    bfs();
    scanf("%d", &m);
    getchar();
    while (m--) {
        string p;
        getline(cin, p);
        if (isRight(p)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}