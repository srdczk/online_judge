class Solution {
public:
    // union find

    unordered_map<int, int> father;

    unordered_map<int, int> cnt;

    int findFather(int i) {
        int t = i;
        while (father[i] != i) {
            i = father[i];
        }
        while (t != i) {
            int n = father[t];
            father[t] = i;
            t = n;
        }
        return i;
    }

    void unionT(int i, int j) {
        int fi = findFather(i), fj = findFather(j);
        if (fi > fj) swap(fi, fj);
        if (fi != fj) {
            father[fi] = fj;
            cnt[fj] += cnt[fi];
        }
    }

    int unionSolve(vector<int> &nums) {
        int res = 0;
        for (auto &num : nums) {
            father[num] = num;
            cnt[num] = 1;
        }
        for (auto &num : nums) {
            if (father.count(num - 1)) unionT(num, num - 1);
            if (father.count(num + 1)) unionT(num, num + 1);
            res = max(res, cnt[findFather(num)]);
        }
        return res;
    }

    void heapify(vector<int> &nums, int index, int size) {
        int left = 2 * index + 1;
        while (left < size) {
            int smallest = left + 1 < size && nums[left + 1] < nums[left] ? left + 1 : left;
            if (nums[index] < nums[smallest]) return;
            swap(nums[index], nums[smallest]);
            index = smallest;
            left = 2 * index + 1;
        }
    }

    int heapSolve(vector<int> &nums) {
        if (nums.empty()) return 0;
        for (int i = (nums.size() - 1) / 2; i > -1; --i) heapify(nums, i, nums.size());
        int cnt = 1, now = nums[0], size = nums.size(), res = 1;
        while (size) {
            swap(nums[0], nums[--size]);
            heapify(nums, 0, size);
            if (nums[0] == now + 1) {
                cnt++;
                now++;
            } else if (nums[0] != now) {
                res = max(cnt, res);
                cnt = 1;
                now = nums[0];
            }
        }
        res = max(res, cnt);
        return res;
    }

    int longestConsecutive(vector<int>& nums) {
        return heapSolve(nums);
        // return unionSolve(nums);
    }
};