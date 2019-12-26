#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void replaceSpace(char *s,int n) {
		int i = 0;
		while (i < n) {
			if (s[i] == ' ') {
				replace(s, i, n);
				n += 2;
				i += 3;
			} else ++i;
		}
	}
private:
	void replace(char *s, int i, int n) {
		memcpy(s + i + 3, s + i + 1, n - i);
		s[i] = '%';
		s[i + 1] = '2';
		s[i + 2] = '0';
	}
};