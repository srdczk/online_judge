#include <bits/stdc++.h>

using namespace std;

int main() {
    double res = 1;
    char s[] = {'W', 'T', 'L'};
    vector<double> a(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) scanf("%lf", &a[j]);
        int k = max_element(a.begin(), a.end()) - a.begin();
        printf("%c ", s[k]);
        res *= a[k];
    }
    printf("%.2f\n", (res * 0.65 - 1) * 2);
    return 0;
}