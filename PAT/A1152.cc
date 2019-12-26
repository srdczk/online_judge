#include <bits/stdc++.h>

using namespace std;

const int BUFSIZE = 1024;

vector<bool> a;

void init(int m) {
    a = vector<bool>((int)pow(10, m), 1);
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < a.size(); ++i) {
        if (!a[i]) continue;
        for (int k = 2; k * i < a.size(); ++k) {
            a[k * i] = 0;
        }
    }
}

void res(const string &p, const int &m) {
    for (int i = 0; i < p.size() - m + 1; ++i) {
        int x = stoi(p.substr(i, m));
        if (a[x]) {printf("%s\n", p.substr(i, m).data()); return; }
    }
    printf("404\n");
}

bool isPrime(int n) {
    if (n < 4) return !n || n == 1 ? 0 : 1;
    for (int i = 2; i <= (int)(sqrt(n)); ++i) {
        if (!(n % i)) return 0;
    }
    return 1;
}

void pd(const string &p, const int &m) {
    for (int i = 0; i < p.size() - m + 1; ++i) {
        int x = stoi(p.substr(i, m));
        if (isPrime(x)) {printf("%s\n", p.substr(i, m).data()); return; }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char s[BUFSIZE];
    scanf("%s", s);
    string p(s);
    if (m > 7) {
        pd(p, m);
        return 0;
    }
    init(m);
    res(p, m);
    return 0;
}
