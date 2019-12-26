#include <bits/stdc++.h>

using namespace std;

vector<int> res(int n, int m) {
    vector<int> a;
    while (n) {
        a.push_back(n % m);
        n /= m;
    }
    return a;
}

bool isPali(const vector<int> &a) {
    int i = 0, j = a.size() - 1;
    while (i < j) {
        if (a[i++] != a[j--]) return 0;
    }
    return 1;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a = res(n, m);
    if (isPali(a)) printf("Yes\n");
    else printf("No\n");
    for (int i = a.size() - 1; i > -1; --i) {
        if (i != a.size() - 1) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
