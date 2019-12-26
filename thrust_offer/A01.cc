#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool Find(int t, vector<vector<int> > a) {
        // 从左下角 开始寻找
		if (!a.size() || !a[0].size()) return 0;
		int i = a.size() - 1, j = 0;
		while (i > - 1 && i < a.size() && j > -1 && j < a[0].size()) {
			if (a[i][j] == t) return 1;
			else if (a[i][j] > t) i--;
			else j++;
		}
		return 0;
    }
};
