#include <bits/stdc++.h>

using namespace std;
const int maxV = 410;
int n, m, k;

vector<int> fac, xFac, res;
vector<bool> pd(maxV, 1);
int gSum = -1;

int myPow(int i, int k) {
    int res = 1;
    while (k) {
        res *= i;
        k--;
    }
    return res;
}

void init() {
    int i = 1;
    while (1) {
        int x = myPow(i, k);
        if (x > n) return;
        fac.push_back(i);
        xFac.push_back(x);
        i++;
    }
}

bool cmp(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return 0;
    }
    return 0;
}


void dfs(vector<int> &a, int level, int t, int sum) {
    if (a.size() == m) {
        if (!t) {
            if (gSum < sum) { res = a; gSum = sum; }
            else if (gSum == sum) {
                if (cmp(a, res)) res = a;
            }
        }
        return;
    }
    if (!t) return;
    for (int i = level; i > -1; --i) {
        if (t >= xFac[i]) {
            a.push_back(fac[i]);
            dfs(a, i, t - xFac[i], sum + fac[i]);
            a.pop_back();
        }
    }
}


int main() {
    scanf("%d%d%d", &n, &m, &k);
    init();
    vector<int> a;
    dfs(a, fac.size() - 1, n, 0);
    if (!res.size()) printf("Impossible\n");
    else {
        printf("%d = ", n);
        for (int i = 0; i < res.size(); ++i) {
            if (i) printf(" + ");
            printf("%d^%d", res[i], k);
        }
        printf("\n");
    }
    return 0;
}
