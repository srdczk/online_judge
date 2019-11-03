#include <bits/stdc++.h>

using namespace std;

int res(int k) {
    string s = to_string(k);
    while (s.size() < 4) s += '0';
    string a = s;
    sort(a.begin(), a.end());
    sort(s.begin(), s.end(), greater<char>());
    printf("%s - %s = ", s.data(), a.data());
    //cout << s << " " << a << "  ";
    return stoi(s) - stoi(a);
}

int main() {
    int x;
    scanf("%d", &x);
    if (x == 6174) {
        printf("%04d\n", (x = res(x)));
        return 0;
    }
    while (x && x != 6174) {
        printf("%04d\n", (x = res(x)));
        //cout << (x = res(x)) << endl;
    }
    return 0;
}
