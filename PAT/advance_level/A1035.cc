#include <bits/stdc++.h>

using namespace std;

struct Node {
    string a, b;
    Node(string _a, string _b): a(_a), b(_b) {}
};

int main() {
    int n, sum;
    scanf("%d", &n);
    sum = n;
    vector<Node> res;
    while (n--) {
        string a, b;
        cin >> a >> b;
        bool x = 0;
        //1 @, 0 %, l L, O o
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] == '1' || b[i] == '0' || b[i] == 'l' || b[i] == 'O') {
                x = 1;
                if (b[i] == '1') b[i] = '@';
                else if (b[i] == '0') b[i] = '%';
                else if (b[i] == 'l') b[i] = 'L';
                else b[i] = 'o';
            }
        }
        if (x) res.push_back(Node(a, b));
    }
    if (!res.size()) {
        if (sum == 1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified", sum);
        //printf("%d", cnt);
    } else {
        printf("%d\n", res.size());
        for (auto &c : res) {
            printf("%s %s\n", c.a.data(), c.b.data());
        }
    }
    return 0;
}
