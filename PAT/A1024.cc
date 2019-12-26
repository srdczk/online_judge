#include <bits/stdc++.h>

using namespace std;


bool isPali(string a) {
    int i = 0, j = a.size() - 1;
    while (i < j) {
        if (a[i++] != a[j--]) return 0;
    }
    return 1;
}


string add(string a, string b) {
    string s = "";
    int i = a.size() - 1, j = b.size() - 1, l = 0;
    while (i > -1 && j > -1) {
        int m = a[i--] - '0', n = b[j--] - '0';
        if (m + n + l > 9) {
            s = to_string(m + n + l - 10) + s;
            l = 1;
        } else {
            s = to_string(m + n + l) + s;
            l = 0;
        }
    }

    while (i > -1) {
        int m = a[i--] - '0';
        if (m + l > 9) {
            s = to_string(m + l - 10) + s;
            l = 1;
        } else {
            s = to_string(m + l) + s;
            l = 0;
        }
    }
    while (j > -1) {
        int m = b[j--] - '0';
        if (m + l > 9) {
            s = to_string(m + l - 10) + s;
            l = 1;
        } else {
            s = to_string(m + l) + s;
            l = 0;
        }
    }
    if (l) s = "1" + s;

    return s;

}

string rever(string a) {
    reverse(a.begin(), a.end());
    return a;
}

pair<string, int> res(string a, int b) {
    int cnt = 0;
    if (isPali(a)) return pair<string, int>(a, cnt);
    while (cnt < b) {
        a = add(a, rever(a));
        cnt++;
        if (isPali(a)) return pair<string, int>(a, cnt);
    }
    return pair<string, int>(a, cnt);
}



int main() {
    string a;
    int b;
    cin >> a >> b;
    pair<string, int> ans = res(a, b);
    cout << ans.first << endl;
    cout << ans.second << endl;

    return 0;
}
