#include <bits/stdc++.h>

using namespace std;

string x[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C"};

string toString(int a) {
    string res = "";
    while (a) {
        res = x[a % 13] + res;
        a /= 13;
    }
    if (res.size() < 2) {
        while (res.size() < 2) res = '0' + res;
    }
    return res;
}

int main() {

    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);

    printf("#%s%s%s\n", toString(x).data(), toString(y).data(), toString(z).data());

    return 0;
}
