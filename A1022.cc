#include <bits/stdc++.h>

using namespace std;

unordered_map<string, set<int>> m[5];

vector<string> split(string a) {
    vector<string> res;
    char *p = const_cast<char *>(a.data());
    char *t = " ";
    char *s = strtok(p, t);
    if (s) res.push_back(string(s));
    while (s = strtok(NULL, t)) res.push_back(string(s));
    return res;
}

void process(string a) {
    printf("%s\n", a.data());
    int p = a.find(':');
    int k = stoi(a.substr(0, p));
    string s = a.substr(p + 2);
    if (!m[k - 1].count(s)) printf("Not Found\n");
    else {
        for (auto &c : m[k - 1][s]) {
            printf("%07d\n", c);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        string a[6];
        for (int i = 0; i < 6; ++i) getline(cin, a[i]);
        int sp = stoi(a[0]);
        for (int i = 0; i < 5; ++i) {
            if (i == 2) continue;
            m[i][a[i + 1]].insert(sp);
        }
        vector<string> vs = split(a[3]);
        for (auto &c : vs) m[2][c].insert(sp);
    }
    int k;
    scanf("%d", &k);
    getchar();
    while (k--) {
        string a;
        getline(cin, a);
        process(a);
    }
    return 0;
}
