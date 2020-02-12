#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (auto &c : nums) {
            if (set.count(c)) return c;
            set.insert(c);
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> a{0, 1, 2, 3, 4, 0};
    cout << solution.findRepeatNumber(a);
    return 0;
}
