class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int leftMin = prices[0], res = 0;
        for (auto &price : prices) {
            leftMin = min(leftMin, price);
            res = max(res, price - leftMin);
        }
        return res;
    }
};