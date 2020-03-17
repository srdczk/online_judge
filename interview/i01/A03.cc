#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &a) {
        int x = 0, y = 0, m = 1, n = 0, p = 0, q = 0;
        int dir = 0;
        vector<int> res{};
        if (!a.size() || !a[0].size()) return res;
        while (res.size() < a[0].size() * a.size()) {
            res.push_back(a[x][y]);
            switch(dir) {
            case 0:
                y++;
                if (y == a[0].size() - 1 - n) {
                    dir = 1;
                    n++;
                }
                break;
            case 1:
                x++;
                if (x == a.size() - 1 - p) {
                    dir = 2;
                    p++;
                }
                break;
            case 2:
                y--;
                if (y == q) {
                    q++;
                    dir = 3;
                }
                break;
            case 3:
                x--;
                if (x == m) {
                    m++;
                    dir = 0;
                }
                break;
            }
        }
        return res;
    }
};
