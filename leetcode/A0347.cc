class Solution {
public:
    struct Node {
        int key, cnt;
    };
    vector<Node *> nodes;
    void heapify(int index, int size) {
        int left = 2 * index + 1;
        while (left < size) {
            int largest = left + 1 < size && nodes[left + 1]->cnt > nodes[left]->cnt ? left + 1 : left;
            if (nodes[index]->cnt >= nodes[largest]->cnt) return;
            swap(nodes[index], nodes[largest]);
            index = largest;
            left = 2 * index + 1;
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, Node *> um;
        vector<int> res;
        for (auto &num : nums) {
            if (!um.count(num)) {
                um[num] = new Node{num, 1};
            } else {
                um[num]->cnt++;
            }
        }
        for (auto &it : um) nodes.push_back(it.second);
        for (int i = (nodes.size() - 1) / 2; i > -1; --i) heapify(i, nodes.size());
        int size = nodes.size();
        while (res.size() < k) {
            res.push_back(nodes[0]->key);
            swap(nodes[0], nodes[--size]);
            heapify(0, size);
        }
        return res;
    }
};