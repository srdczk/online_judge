#include <bits/stdc++.h>

using namespace std;

const int BUFSIZE = 1024;

struct Node {
    int id;
    string name;
    int grade;
    Node() {}
    Node(int i, const char *s, int g): id(i), name(s), grade(g) {}
};

int main() {

    int n, c;
    scanf("%d%d", &n, &c);
    char s[BUFSIZE];
    vector<Node> a(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%s%d", &x, s, &y);
        a[i].id = x;
        a[i].name = s;
        a[i].grade = y;
    }
    if (c == 1) {
        sort(a.begin(), a.end(), [](const Node &a, const Node &b) {return a.id < b.id;});
    } else if (c == 2) {
        sort(a.begin(), a.end(), [](const Node &a, const Node &b) {return a.name <= b.name;});
    } else {
        sort(a.begin(), a.end(), [](const Node &a, const Node &b) {return a.grade <= b.grade;});
    }
    for (auto &c : a) {
        printf("%06d %s %d\n", c.id, c.name.data(), c.grade);
    }
    return 0;
}
