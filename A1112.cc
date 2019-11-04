#include <bits/stdc++.h>

using namespace std;
const int BUFSIZE = 1024;

vector<char> res;

unordered_set<char> p, q;

void process(const char *s, int k) {
    char x = s[0];
    int cnt = 1;
    for (int i = 1; i < strlen(s); ++i) {
        if (s[i] == x) cnt++;
        else {
            if (!(cnt % k)) {
                if (!p.count(x)) {
                    if (!q.count(x)) {
                        q.insert(x);
                        res.push_back(x);
                    }
                }
            } else {
                if (q.count(x)) {
                    q.erase(q.find(x));
                    res.erase(find(res.begin(), res.end(), x));
                }
                p.insert(x);
            }
            x = s[i];
            cnt = 1;
        }
    }
    if (!(cnt % k)) {
            if (!p.count(x)) {
                if (!q.count(x)) {
                    q.insert(x);
                    res.push_back(x);
                }
            }
        } else {
            if (q.count(x)) {
                q.erase(q.find(x));
                res.erase(find(res.begin(), res.end(), x));
            }
            p.insert(x);
        }
}

int main() {
    int n;
    scanf("%d", &n);
    char s[BUFSIZE];
    scanf("%s", s);
    process(s, n);
    for (auto &c : res) printf("%c", c);
    printf("\n");
    int i = 0;
    while (i < strlen(s)) {
        printf("%c", s[i]);
        if (q.count(s[i])) {
            i += n;
        } else i++;
    }
    printf("\n");
    return 0;
}
