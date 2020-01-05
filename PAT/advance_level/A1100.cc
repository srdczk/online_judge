#include <bits/stdc++.h>

using namespace std;

string sa[] = {"tret",  "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string sb[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

unordered_map<string, int> sm;

void toString(string a) {
    if (a[0] >= '0' && a[0] <= '9') {
        int p = stoi(a);
        vector<string> res;
        if (p % 13 || !p) res.push_back(sa[p % 13]);
        if (p / 13) res.insert(res.begin(), sb[p / 13 - 1]);
        for (int i = 0; i < res.size(); ++i) {
            if (i) printf(" ");
            printf("%s", res[i].data());
        }
        printf("\n");
    } else {
        if (a.find(' ') == string::npos) {
            printf("%d\n", sm[a]);
        } else {
            int p = a.find(' ');
            string x = a.substr(0, p), y = a.substr(p + 1);
            printf("%d\n", sm[x] + sm[y]);
        }
    }
}

int main() {
    for (int i = 0; i < 13; ++i) sm[sa[i]] = i;
    for (int i = 0; i < 12; ++i) sm[sb[i]] = (i + 1) * 13;
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        string a;
        getline(cin, a);
        toString(a);
    }

    return 0;
}
