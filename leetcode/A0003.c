#define SIZE 128

int lengthOfLongestSubstring(char * s){
	int map[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		map[i] = -1;
	}
	int res = 0;
	for (int i = 0, j = 0; s[i]; ++i) {
		if (map[s[i]] >= j) j = map[s[i]] + 1;
		map[s[i]] = i;
		if (i - j + 1 > res) res = i - j + 1;
	}
	return res;
}