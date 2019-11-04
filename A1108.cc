#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool x;
    string res;
    Node(bool _x, string s): x(_x), res(s) {}
};

bool process(const string &s) {
    try {
        double d = stod(s);
        if (abs(d) > 1000) return 0;
        if (s.find('.') != string::npos && s.substr(s.find('.') + 1).size() > 2) return 0;
        return 1;
    } catch (exception e) {
        return 0;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;
    int cnt = 0;
    while (n--) {
        string s;
        cin >> s;
        if (process(s)) {
            double d = stod(s);
            sum += d;
            cnt++;
        } else {
            printf("ERROR: %s is not a legal number\n", s.data());
        }
    }
    if (!cnt) printf("The average of 0 numbers is Undefined\n");
    else if (cnt == 1) printf("The average of 1 number is %.2f\n", sum);
    else printf("The average of %d numbers is %.2f\n", cnt, sum / (double)cnt);
    return 0;
}
