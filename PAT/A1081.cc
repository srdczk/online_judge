#include <bits/stdc++.h>

using namespace std;

const int BUFSIZE = 1024;

long gcd(long a, long b) {
    return b ? gcd(b, a % b) : a;
}

struct Node {
    long a, b;
    Node(long _a, long _b): a(_a), b(_b) {}
};

Node add(const Node &x, const Node &y) {
    long ap = x.a * y.b + y.a * x.b, bp = x.b * y.b, g = gcd(abs(ap), bp);
    return Node(ap / g, bp / g);
}

Node toNode(string s) {
    int p = s.find('/');
    return Node(stol(s.substr(0, p)), stol(s.substr(p + 1)));
}

int main() {
    int n;
    char s[BUFSIZE];
    scanf("%d", &n);
    Node res(0, 1);
    while (n--) {
        scanf("%s", s);
        res = add(res, toNode(string(s)));
    }
    if (!(res.a % res.b)) printf("%ld\n", res.a / res.b);
    else {
        if (abs(res.a) > res.b) {
            if (res.a < 0) printf("-%ld %ld/%ld\n", abs(res.a) / res.b, abs(res.a) % res.b, res.b);
            else printf("%ld %ld/%ld\n", res.a / res.b, res.a % res.b, res.b);
        } else printf("%ld/%ld\n", res.a, res.b);
    }
    //cout << res.a << " " << res.b << endl;
    return 0;
}
