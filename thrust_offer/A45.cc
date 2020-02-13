#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            string x = to_string(a) + to_string(b), y = to_string(b) + to_string(a);
            return x < y;
        });
        string res = "";
        for (auto &num : nums) {
            res += to_string(num);
        }
        return res;
    }
};

int main() {
    vector<int> a{5, 4, 23, 20, 3};
    Solution s;
    cout << s.minNumber(a);
    return 0;
}
