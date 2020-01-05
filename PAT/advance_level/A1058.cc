#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, b, c;
    Node() {}
    Node(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
};


Node add(const Node &a, const Node &b) {
    int z = a.c + b.c, y = a.b + b.b, x = a.a + b.a;
    if (z > 28) y += z / 29;
    z %= 29;
    if (y > 17) x += y / 17;
    y %= 17;
    return Node(x, y, z);
}

int toInt(Node node) {
    return node.a * 29 * 17 + node.b * 29 + node.c;
}

Node toNode(int a) {
    return Node(a / (29 * 17), (a % (29 * 17)) / 29, a % 29);
}

int main() {
    Node a, b, c;
    scanf("%d.%d.%d %d.%d.%d", &a.a, &a.b, &a.c, &b.a, &b.b, &b.c);
    if (a.a == 10000000 || b.a == 10000000) {
        c = add(a, b);
    } else c = toNode(toInt(a) + toInt(b));
    printf("%d.%d.%d\n", c.a, c.b, c.c);
    return 0;
}
