class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        // cnt 0
        int res = 0;
        int num = 0;
        for (int i = 0, j = 0; i < a.size(); ++i) {
            if (!a[i]) num++;
            while (num > k) {
                if (!a[j++]) num--;
            }
            res = max(i - j + 1, res);
        }
        return res;
    }
};