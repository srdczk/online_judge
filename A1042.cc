#include <bits/stdc++.h>

using namespace std;

char cs[] = {'S', 'H', 'C', 'D', 'J'};

void bt(vector<string> &p, const vector<int> &a) {
    vector<string> q = p;
    for (int i = 0; i < a.size(); ++i) {
        p[a[i]] = q[i];
    }
}

int main() {

    int n;
    scanf("%d", &n);
    vector<int> a(54);
    for (int i = 0; i < a.size(); ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x - 1;
    }
    vector<string> p(54);
    for (int i = 0; i < p.size(); ++i) {
        p[i] = (cs[i / 13] + to_string(i % 13 + 1));
    }
    while (n--) bt(p, a);
    for (int i = 0; i < p.size(); ++i) {
        if (i) printf(" ");
        printf("%s", p[i].data());
    }
    printf("\n");
    return 0;
}
