int strlen(const char *s) {
	int res = 0;
	while (*s++) res++;
	return res;
}

void process(char *s, const char *p, int len) {
	for (int i = 0; i < (2 * len + 1); ++i) {
		if (i % 2) s[i] = p[i / 2];
		else s[i] = '#';
	}
	p[2 * len + 1] = '\0';
}

int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a > b ? a : b; }

char *longestPalindrome(char * s){
	int len = strlen(s);
	char p[2 * len + 2];
	process(p, s, len);
	int R = -1, C = -1;
	int pArray[2 * len + 1];
	int start = 0, res = 1;
	for (int i = 0; i < 2 * len + 1; ++i) {
		pArray[i] = R > i ? min(R - i, pArray[2 * C - i]) : 1;
		
		while (i + pArray[i] < 2 * len + 2 && i - pArray[i] > -1) {
			if (p[i + pArray[i]] == p[i - pArray[i]]) {
				pArray[i]++;
			} else break;
		}
		
		if (i + pArray[i] > R) {
			R = i + pArray[i];
			C = i;
		}
		if (pArray[i] > res) {
			res = pArray[i];
			start = (i - pArray[i]) / 2;
		}
		
	}
	s[start + res] = '\0';
	return s + start;
}