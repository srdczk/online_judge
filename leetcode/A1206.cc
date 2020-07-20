class Skiplist {
public:
    struct Node {
        int val;
        Node *right, *down;
        Node(int v): val(v), right(nullptr), down(nullptr) {}
        Node(int v, Node *r, Node *d): val(v), right(r), down(d) {}
    };
    Node *head;
    Skiplist() {
        head = new Node(-1);
    }
    
    bool search(int target) {
        Node *p = head;
        while (p) {
            while (p->right && p->right->val < target) p = p->right;
            if (p->right && p->right->val == target) return true;
            p = p->down;
        }
        return false;
    }
    
    void add(int num) {
        vector<Node *> path;
        Node *p = head;
        while (p) {
            while (p->right && p->right->val < num) p = p->right;
            path.push_back(p);
            p = p->down;
        }
        bool insertUp = true;
        Node *downNode = nullptr;
        while (path.size() && insertUp) {
            auto node = path.back();
            path.pop_back();
            node->right = new Node(num, node->right, downNode);
            downNode = node->right;
            insertUp = rand() & 1;
        }
        if (insertUp) 
            // add to head
            head = new Node(-1, new Node(num, nullptr, downNode), head);
    }
    
    bool erase(int num) {
        bool res = false;
        Node *p = head;
        while (p) {
            while (p->right && p->right->val < num) p = p->right;
            if (p->right && p->right->val == num) {
                res = true;
                p->right = p->right->right;
            }
            p = p->down;
        }

        return res;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */