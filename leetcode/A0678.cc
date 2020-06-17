#include <bits/stdc++.h>

using namespace std;

string process(string &s) {
    string res;
    for (auto &c : s) {
        if (res.size() > 1 && res[res.size() - 1] == c && res[res.size() - 1] == res[res.size() - 2]) continue;
        if (res.size() > 2 && res[res.size() - 1] == c && res[res.size() - 2] == res[res.size() - 3]) continue;
        res.push_back(c);
    }
    return res;
}

auto main() -> decltype(0) {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        string s;
        getline(cin, s);
        cout << process(s) << "\n";
    }
    return 0;
}