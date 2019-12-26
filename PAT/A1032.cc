#include <bits/stdc++.h>

using namespace std;
const int maxV = 100010;
struct Node {
    int addr;
    char c;
    int next;
    Node() {}
    Node(int a, char _c, int n): addr(a), c(_c), next(n) {}
};

vector<Node> ns(maxV);

int main() {
    int ba, bb, n;
    scanf("%d%d%d", &ba, &bb, &n);
    while (n--) {
        int a, b;
        char c;
        cin >> a >> c >> b;
        ns[a] = Node(a, c, b);
    }
    unordered_set<int> sa;
    while (ba != -1) {
        sa.insert(ba);
        ba = ns[ba].next;
    }
    while (bb != -1) {
        if (sa.count(bb)) {
            printf("%05d\n", bb);
            return 0;
        }
        bb = ns[bb].next;
    }
    printf("-1\n");
    return 0;
}