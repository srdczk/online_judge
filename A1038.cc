#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), [](string x, string y) { if ((x + y) < (y + x)) return 1; else return 0; } );
    string res = "";
    for (auto &c : a) res += c;
    int i = 0;
    while (i < res.size() && res[i] == '0') i++;
    if (i == res.size()) printf("0\n");
    else printf("%s\n", res.substr(i).data());
    return 0;
}
