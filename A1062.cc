#include <bits/stdc++.h>

using namespace std;
const int BUFSIZE = 1024;
struct Node {
    string id;
    int a, b;
    //Node() {}
    Node(const char *x, int _a, int _b): id(x), a(_a), b(_b) {}
};

int main() {

    int n, x, y;
    char s[BUFSIZE];
    scanf("%d%d%d", &n, &x, &y);
    vector<Node> sa, sb, sc, sd;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%s%d%d", s, &a, &b);
        if (a >= x && b >= x) {
            if (a >= y && b >= y) {
                sa.push_back(Node(s, a, b));
            } else if (b < y && a >= y) {
                sb.push_back(Node(s, a, b));
            } else if (b < y && a < y && a >= b) {
                sc.push_back(Node(s, a, b));
            } else sd.push_back(Node(s, a, b));
        }
        //as.push_back(Node(s, a,// << " " << b << endl;
    }
    sort(sa.begin(), sa.end(), [=](const Node &p, const Node &q) {if (p.a + p.b != q.a + q.b) {return p.a + p.b > q.a + q.b;} else if (p.a != q.a) {return p.a > q.a;} else return p.id < q.id;});
    sort(sb.begin(), sb.end(), [=](const Node &p, const Node &q) {if (p.a + p.b != q.a + q.b) {return p.a + p.b > q.a + q.b;} else if (p.a != q.a) {return p.a > q.a;} else return p.id < q.id;});
    sort(sc.begin(), sc.end(), [=](const Node &p, const Node &q) {if (p.a + p.b != q.a + q.b) {return p.a + p.b > q.a + q.b;} else if (p.a != q.a) {return p.a > q.a;} else return p.id < q.id;});
    sort(sd.begin(), sd.end(), [=](const Node &p, const Node &q) {if (p.a + p.b != q.a + q.b) {return p.a + p.b > q.a + q.b;} else if (p.a != q.a) {return p.a > q.a;} else return p.id < q.id;});

    printf("%d\n", sa.size() + sb.size() + sd.size() + sc.size());
    for (auto &c : sa) {

        printf("%s %d %d\n", c.id.data(), c.a, c.b);
    }
    for (auto &c : sb) {

        printf("%s %d %d\n", c.id.data(), c.a, c.b);
    }
    for (auto &c : sc) {

        printf("%s %d %d\n", c.id.data(), c.a, c.b);
    }
    for (auto &c : sd) {

        printf("%s %d %d\n", c.id.data(), c.a, c.b);
    }
    return 0;
}
