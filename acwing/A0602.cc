#include <bits/stdc++.h>

using namespace std;
auto main() -> int {
    stack<char> s;
    int n;
    scanf("%d", &n);
    getchar();
    char c;
    while (n--) {
        c = getchar();
        if (!s.empty() && s.top() != c) s.pop();
        else s.push(c);
    }
    printf("%d\n", s.size());
    return 0;
}
