#include <bits/stdc++.h>

using namespace std;
const int BUFSIZE = 110;

string ss[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int sum(const char *s) {
    int ans = 0;
    for (int i = 0; i < strlen(s); ++i) {
        ans += s[i] - '0';
    }
    return ans;
}

int main() {
    char a[BUFSIZE];
    scanf("%s", a);
    string s = to_string(sum(a));
    for (int i = 0; i < s.length(); ++i) {
        if (i) printf(" ");
        printf("%s", ss[s[i] -'0'].data());
    }
    printf("\n");
    return 0;
}