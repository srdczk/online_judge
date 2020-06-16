class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.empty()) return 0;
        if (arr.size() == 1) return arr[0];
        vector<int> dpA(arr.size(), 0), dpB(arr.size(), 0);
        // dpA -> have del one, dpB, not del
        int res = arr[0];
        dpB[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            // dpB[i]
            if (dpB[i - 1] > 0) dpB[i] = dpB[i - 1] + arr[i];
            else dpB[i] = arr[i];
            dpA[i] = max(dpA[i - 1] + arr[i], dpB[i - 1]);
            res = max(res, max(dpA[i], dpB[i]));
        }
        return res;
    }
};