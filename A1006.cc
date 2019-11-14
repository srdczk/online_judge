#include <bits/stdc++.h>

using namespace std;
const int BUFSIZE = 512;

int toInt(int x, int y, int z) {
    return z + y * 60 + x * 60 * 60;
}

int main() {
    string a, b;
    char s[BUFSIZE];
    int MIN = INT_MAX, MAX = INT_MIN, n;
    scanf("%d", &n);
    while (n--) {
        int p, q, r, x, y, z;
        scanf("%s %d:%d:%d %d:%d:%d", s, &p, &q, &r, &x, &y, &z);
        if (toInt(p, q, r) < MIN) {
            MIN = toInt(p, q, r);
            a = s;
        }
        if (toInt(x, y ,z) > MAX) {
            MAX = toInt(x, y ,z);
            b = s;
        }
    }
    printf("%s %s\n", a.data(), b.data());
    return 0;
}