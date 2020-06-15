class Solution {
public:
    struct Cmp {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        }
    };
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Cmp> heap;
        unordered_map<int, int> map;
        for (auto &a : arr) ++map[a];
        for (auto &it : map) heap.push({it.first, it.second});
        while (k && !heap.empty()) {
            auto p = heap.top();
            if (k >= p[1]) {
                k -= p[1];
                heap.pop();
            } else k = 0;
        }
        return heap.size();
    }
};