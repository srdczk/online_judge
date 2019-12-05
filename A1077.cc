#include <bits/stdc++.h>

using namespace std;

const int BUFSIZE = 1024;

string process(const string &a, const string &b) {
    string res = "";
    int i = a.size() - 1, j = b.size() - 1;
    while (i > -1 && j > -1) {
        if (a[i] == b[j]) {
            res = a[i] + res;
            i--;
            j--;
        }
        else break;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    string p;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        if (!i) p = s;
        else p = process(p, s);
    }
    if (!p.size()) printf("nai\n");
    else printf("%s\n", p.data());
    return 0;
}
