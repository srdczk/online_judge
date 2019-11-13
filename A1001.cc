#include <bits/stdc++.h>

using namespace std;

void process(const string &a) {
    if (a[0] == '-') {
        printf("-");
        process(a.substr(1));
        return;
    }
    for (int i = 0; i < a.length(); ++i) {
        if (i && !((a.length() - i) % 3)) printf(",");
        printf("%c", a[i]);
    }
    printf("\n");
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    process(to_string(a + b));
    return 0;
}