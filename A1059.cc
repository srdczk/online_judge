#include <bits/stdc++.h>

using namespace std;

struct Node {
    long val, c;
    Node(long v): val(v), c(1) {}
};

vector<Node> res;

void dfs(long n) {
    bool x = 0;
    for (long i = 2; i <= (long)(sqrt(n)); ++i) {
        if (!(n % i)) {
            x = 1;
            if (!res.size()) res.push_back(i);
            else if (res[res.size() - 1].val == i) res[res.size() - 1].c++;
            else res.push_back(i);
            dfs(n / i);
            break;
        }
    }
    if (!x) {
        if (!res.size()) res.push_back(n);
        else if (res[res.size() - 1].val == n) res[res.size() - 1].c++;
        else res.push_back(n);
    }
}

int main() {

    long a;
    cin >> a;
    dfs(a);
    cout << a << "=";
    //for (auto &c : res) cout << c.val << " " << c.c << endl;
    for (int i = 0; i < res.size(); ++i) {
        if (i) printf("*");
        if (res[i].c == 1) cout << res[i].val;
        else cout << res[i].val << "^" << res[i].c;
        //else printf("%ld^%ld", res[i].val, res[i].c);
    }
    cout << endl;
    //printf("\n");
    return 0;
}
