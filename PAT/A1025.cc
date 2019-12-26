#include <bits/stdc++.h>

using namespace std;

const int BUFSIZE = 1024;

struct Node {
    int g, a, b, c;
    Node() {}
};

unordered_map<string, Node> m;

int main() {
    int n;
    char a[BUFSIZE];
    scanf("%d", &n);
    vector<string> s;
    vector<string> as[n];
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if (k) {
            as[i] = vector<string>(k);
            for (int j = 0; j < k; ++j) {
                int p;
                scanf("%s%d", a, &p);
                string ap(a);
                m[ap].g = p;
                m[ap].b = i + 1;
                as[i][j] = ap;
                s.push_back(ap);
            }
            sort(as[i].begin(), as[i].end(), [=](const string &a, const string &b) {return m[a].g > m[b].g;});
            m[as[i][0]].c = 1;
            int gp = m[as[i][0]].g, x = 1;
            for (int j = 1; j < as[i].size(); ++j) {
                if (m[as[i][j]].g != gp) {
                    gp = m[as[i][j]].g;
                    x = j + 1;
                }
                m[as[i][j]].c = x;
            }
        }
    }
    sort(s.begin(), s.end(), [=](const string &a, const string &b) {
         if (m[a].g == m[b].g) {
            return a < b;
         } else return m[a].g > m[b].g;
        });
    m[s[0]].a = 1;
    int gp = m[s[0]].g, x = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (m[s[i]].g != gp) {
            gp = m[s[i]].g;
            x = i + 1;
        }
        m[s[i]].a = x;
    }
    printf("%d\n", s.size());
    for (auto &c : s) {
        if (c.size() < 13) {
            for (int i = 0; i < 13 - c.size(); ++i) printf("0");
        }
        printf("%s %d %d %d\n", c.data(), m[c].a, m[c].b, m[c].c);
    }
    return 0;
}
