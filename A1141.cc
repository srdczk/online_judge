#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    int A, B, T, N;
    int res;
    Node(string n): name(n) {
        A = 0;
        B = 0;
        T = 0;
        N = 0;
        res = 0;
    }
};

void toLower(string &s) {
    for (int i = 0; i < s.length(); ++i) {
        s[i] = tolower(s[i]);
    }
}

unordered_map<string, int> sm;

int main() {
    int n;
    scanf("%d", &n);
    vector<Node> ns;
    while (n--) {
        string n, name;
        int c;
        cin >> n >> c >> name;
        toLower(name);
        if (!sm.count(name)) {
            ns.push_back(Node(name));
            sm[name] = ns.size() - 1;
        }
        ns[sm[name]].N++;
        if (n[0] == 'A') ns[sm[name]].A += c;
        else if (n[0] == 'B') ns[sm[name]].B += c;
        else ns[sm[name]].T += c;
    }
    for (int i = 0; i < ns.size(); ++i) {
        ns[i].res = (int)(ns[i].A + (double)ns[i].B / 1.5 + (double)ns[i].T * 1.5);
    }
    sort(ns.begin(), ns.end(), [](const Node &a, const Node &b) {
        if (a.res != b.res) return a.res > b.res;
        else if (a.N != b.N) return a.N < b.N;
        else return a.name < b.name;
    });
    int x = ns[0].res, cnt = 1;
    cout << ns.size() << endl;
    for (int i = 0; i < ns.size(); ++i) {
        if (ns[i].res != x) {
            cnt = i + 1;
            x = ns[i].res;
        }
        cout << cnt << " " << ns[i].name << " " << ns[i].res << " " << ns[i].N << endl;
    }
    return 0;
}