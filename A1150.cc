#include <bits/stdc++.h>

using namespace std;
const int maxV = 210;

vector<vector<int>> G(maxV, vector<int>(maxV, 0));

int n, m;

int v;
string d;
void toNode(const vector<int> &a) {
    string des = "";
    int val = 0;
    if (a[0] != a[a.size() - 1]) {
        des = "Not a TS cycle";
    } else {
        unordered_set<int> s(a.begin(), a.end());
        if (s.size() == n) {
            if (a.size() == n + 1) des = "TS simple cycle";
            else des = "TS cycle";
        } else des = "Not a TS cycle";
    }
    for (int i = 1; i < a.size(); ++i) {
        if (!G[a[i - 1]][a[i]]) {
            printf("NA (Not a TS cycle)\n");
            //return Node(INT_MAX, des);
            v = val;
            d = "Not a TS cycle";
            return;
        }
        val += G[a[i - 1]][a[i]];
    }
    v = val;
    d = des;
    printf("%d (%s)\n", val, des.data());
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        G[a][b] = c;
        G[b][a] = c;
    }
    int k;
    scanf("%d", &k);
    int u = -1, MIN = INT_MAX;
    for (int i = 0; i < k; ++i) {
        int cnt;
        scanf("%d", &cnt);
        vector<int> a(cnt);
        for (int j = 0; j < cnt; ++j) scanf("%d", &a[j]);
        printf("Path %d: ", i + 1);
        toNode(a);
        if (d == "TS cycle" || d == "TS simple cycle") {
            if (MIN > v) {
                MIN = v;
                u = i + 1;
            }
        }
        //printf("%d %s\n", node.val, node.des.data());
        //printf("Path %d: ", i + 1);
        //if (node.val == INT_MAX) printf("NA ");
        //else printf("%d ", node.val);
        //printf("(%s)\n", node.des.data());
    }
    printf("Shortest Dist(%d) = %d\n", u, MIN);
    return 0;
}
