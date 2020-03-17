#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> a(k + 1, 1);
        a[0] = 0;
        int res = 1;
        while (a[k] < n) {
            for (int i = k; i > 0; --i) a[i] += (a[i - 1] + 1);
            res++;
        }
        return res;
    }
};
