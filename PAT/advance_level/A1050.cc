#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    unordered_set<char> s;
    for (auto &c : b) s.insert(c);
    string::iterator it = a.begin();
    while (it != a.end()) {
        if (s.count(*it)) it = a.erase(it);
        else ++it;
    }
    printf("%s\n", a.data());
    return 0;
}
