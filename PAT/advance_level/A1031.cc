#include <bits/stdc++.h>

using namespace std;
const int maxV = 100;
char s[maxV];
int main() {
    scanf("%s", s);
    int len = strlen(s), x = (len + 2) / 3;
    for (int i = 0; i < x; ++i) {
        if (i == x - 1) {
            for (int j = i; j < i + len + 2 - 2 * x; ++j) {
                printf("%c", s[j]);
            }
            printf("\n");
        } else {
            printf("%c", s[i]);
            for (int j = 0; j < len - 2 * x; ++j) printf(" ");
            printf("%c\n", s[len - 1 - i]);
        }
    }
    return 0;
}
