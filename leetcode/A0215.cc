class Solution {
public:

    int parition(vector<int> &a, int l, int r, int k) {
        if (l >= r) return a[l];
        int i = l - 1, j = r + 1, x = a[l + ((r - l) >> 1)];
        while (i < j) {
            do ++i; while (a[i] < x);
            do --j; while (a[j] > x);
            if (i < j) swap(a[i], a[j]);
        }
        if (j - l + 1 >= k) return parition(a, l, j, k);
        else return parition(a, j + 1, r, k - (j - l + 1));
    }


    void heapify(vector<int> &a, int index, int size) {
        // max heap
        int left = 2 * index + 1;
        while (left < size) {
            int largest = left + 1 < size && a[left + 1] > a[left] ? left + 1 : left;
            if (a[index] >= a[largest]) return;
            swap(a[index], a[largest]);
            index = largest;
            left = 2 * index + 1;
        }
    }

    int heapSolve(vector<int> &nums, int k) {
        int cnt = 1;
        for (int i = (nums.size() - 1) / 2; i > -1; --i) heapify(nums, i, nums.size());
        int size = nums.size();
        while (cnt < k) {
            swap(nums[0], nums[--size]);
            heapify(nums, 0, size);
            cnt++;
        }
        return nums[0];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k + 1;
        return parition(nums, 0, nums.size() - 1, k);
        // return reSolve(nums, k, 0, nums.size() - 1);
    }

    

};