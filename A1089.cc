#include <bits/stdc++.h>

using namespace std;

bool isInsert(vector<int> &a, const vector<int> &b) {
    bool res = 0;
    for (int i = 1; i < a.size(); ++i) {
        int tmp = a[i], p;
        for (p = i - 1; p > -1 && a[p] > tmp; --p) {
            a[p + 1] = a[p];
        }
        a[p + 1] = tmp;
        if (res) break;
        if (a == b) res = 1;
    }
    return res;
}

bool isMerge(vector<int> &a, const vector<int> &b) {
    bool res = 0;
    for (int i = 2; i / 2 < a.size(); i *= 2) {

        for (int j = 0; j < a.size(); j += i) {
            sort(a.begin() + j, a.begin() + min(j + i, (int) a.size()));
        }
        if (res) break;
        if (a == b) res = 1;
    }
    return res;
}


int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    c = a;
    if (isInsert(a, b)) {
        printf("Insertion Sort\n");
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    } else {
        if (isMerge(c, b)) {
            printf("Merge Sort\n");
            for (int i = 0; i < n; ++i) {
                if (i) printf(" ");
                printf("%d", c[i]);
            }
            printf("\n");
        }
    }
    return 0;
}