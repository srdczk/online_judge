#include <bits/stdc++.h>

using namespace std;

const int BUFSIZE = 1024;

long gcd(long a, long b) {
    return b ? gcd(b, a % b) : a;
}

struct Node {
    long a, b;
    Node() {}
    Node(long _a, long _b) {
        if (!(_a * _b) || _a * _b > 0) {
            _a = abs(_a);
            _b = abs(_b);
        } else {
            _a = -abs(_a);
            _b = abs(_b);
        }
        long g = gcd(abs(_a), _b);
        a = _a / g;
        b = _b / g;
    }
};

Node toNode(string s) {
    int p = s.find('/');
    return Node(stol(s.substr(0, p)), stol(s.substr(p + 1)));
}

Node add(const Node &a, const Node &b) {
    return Node(a.a * b.b + b.a * a.b, a.b * b.b);
}

Node sub(const Node &a, const Node &b) {
    return Node(a.a * b.b - b.a * a.b, a.b * b.b);
}

Node pro(const Node &a, const Node &b) {
    return Node(a.a * b.a, a.b * b.b);
}

Node div(const Node &a, const Node &b) {
    return Node(a.a * b.b, a.b * b.a);
}

string toString(const Node &node) {
    if (!node.b) return "Inf";
    if (!node.a) return "0";
    if (node.a > 0) {
        if (!(node.a % node.b)) {
            return to_string(node.a / node.b);
        } else if (node.a > node.b) {
            return to_string(node.a / node.b) + " " + to_string(node.a % node.b) + "/" + to_string(node.b);
        } else {
            return to_string(node.a) + "/" + to_string(node.b);
        }
    } else {
        Node p = node;
        p.a = -p.a;
        return "(-" + toString(p) + ")";
    }
}

int main() {
    Node a, b;
    char s[BUFSIZE];
    scanf("%s", s);
    a = toNode(s);
    scanf("%s", s);
    b = toNode(s);
    string sa = toString(a), sb = toString(b);
    printf("%s + %s = %s\n", sa.data(), sb.data(), toString(add(a, b)).data());
    printf("%s - %s = %s\n", sa.data(), sb.data(), toString(sub(a, b)).data());
    printf("%s * %s = %s\n", sa.data(), sb.data(), toString(pro(a, b)).data());
    printf("%s / %s = %s\n", sa.data(), sb.data(), toString(div(a, b)).data());
    return 0;
}
