#include <bits/stdc++.h>

using namespace std;
#define BUFSIZE 1024
multiset<int> a, b;

int main() {
    int n;
    scanf("%d", &n);
    stack<int> s;
    char buff[BUFSIZE];
    while (n--) {
        scanf("%s", buff);
        if (!strcmp(buff, "Pop")) {
            if (s.empty()) {
                printf("Invalid\n");
                continue;
            }
            int x = s.top();
            s.pop();
            printf("%d\n", x);
            if (a.size() == b.size()) {
                auto it = b.begin();
                int p = *it;
                if (x >= p) b.erase(b.find(x));
                else {
                    a.erase(a.find(x));
                    b.erase(it);
                    a.insert(p);
                }
            } else {
                auto it = --a.end();
                int p = *it;
                if (x <= p) a.erase(a.find(x));
                else {
                    b.erase(b.find(x));
                    a.erase(it);
                    b.insert(p);
                }
            }
        } else if (!strcmp(buff, "Push")) {
            int x;
            scanf("%d", &x);
            s.push(x);
            if (!a.size()) a.insert(x);
            else if (a.size() == b.size()) {
                auto it = b.begin();
                int p = *it;
                if (x <= p) a.insert(x);
                else {
                    b.erase(it);
                    a.insert(p);
                    b.insert(x);
                }
            } else {
                auto it = --a.end();
                int p = *it;
                if (x >= p) b.insert(x);
                else {
                    a.erase(it);
                    b.insert(p);
                    a.insert(x);
                }
            }
        } else {
            if (s.empty()) {
                printf("Invalid\n");
                continue;
            }
            printf("%d\n", *(--a.end()));
        }
    }
    return 0;
}
