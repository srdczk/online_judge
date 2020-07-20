class LRUCache {
public:
    struct Node {
        int key, val;
        Node *next, *pre;
        Node(int k, int v): key(k), val(v), next(nullptr), pre(nullptr) {}
    };
    unordered_map<int, Node* > keyMap;
    Node *head, *tail;
    int size, capacity;
    LRUCache(int capacity_) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
        size = 0;
        capacity = capacity_;
    }
    
    int get(int key) {
        if (!keyMap.count(key)) return -1;
        auto node = keyMap[key];
        auto pre = node->pre, next = node->next;
        pre->next = next;
        next->pre = pre;
        // insert to head
        next = head->next;
        head->next = node;
        node->next = next;
        next->pre = node;
        node->pre = head;
        return node->val;
    }
    
    void put(int key, int value) {
        if (keyMap.count(key)) {
            auto node = keyMap[key];
            auto pre = node->pre, next = node->next;
            pre->next = next;
            next->pre = pre;
            // insert to head
            next = head->next;
            head->next = node;
            node->next = next;
            next->pre = node;
            node->pre = head;
            node->val = value;
        } else {
            if (size == capacity) {
                // del the last
                auto toDel = tail->pre;
                keyMap.erase(toDel->key);
                auto pre = toDel->pre;
                pre->next = tail;
                tail->pre = pre;
                --size;
            }
            ++size;
            auto next = head->next;
            auto node = new Node(key, value);
            keyMap[key] = node;
            head->next = node;
            node->pre = head;
            node->next = next;
            next->pre = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */