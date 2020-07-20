class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (!arr.size()) return 0;
        vector<int> dpA(arr.size()), dpB(arr.size());
        // dpB represent del 1
        int res = arr[0];
        dpA[0] = arr[0];
        dpB[0] = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (dpA[i - 1] < 0) dpA[i] = arr[i];
            else dpA[i] = dpA[i - 1] + arr[i];
            dpB[i] = max(dpB[i - 1] + arr[i], dpA[i - 1]);
            res = max(res, max(dpA[i], dpB[i]));
        }
        return res;
    }
};