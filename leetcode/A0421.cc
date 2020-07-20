class Solution {
public:
    struct Node {
        Node *left, *right;
        Node(): left(nullptr), right(nullptr) {}
    };

    Node *root = new Node();

    void insert(int num) {
        Node *node = root;
        for (int i = 30; i >= 0; --i) {
            if ((num >> i) & 1) {
                // right
                if (!node->right) node->right = new Node();
                node = node->right;
            } else {
                // left
                if (!node->left) node->left = new Node();
                node = node->left;
            }
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        int res = INT_MIN;
        for (auto &num : nums) {
            insert(num);
            int x = 0;
            Node *node = root;
            for (int i = 30; i >= 0; --i) {
                int p = ((num >> i) & 1);
                if (p) {
                    if (node->left) {
                        node = node->left;
                        x |= (1 << i);
                    } else node = node->right;
                } else {
                    if (node->right) {
                        node = node->right;
                        x |= (1 << i);
                    } else node = node->left;
                }
            }
            res = max(res, x);
        }
        return res;
    }
};