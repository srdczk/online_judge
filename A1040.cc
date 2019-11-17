#include <bits/stdc++.h>

using namespace std;
string process(const string &a) {
    string res(2 * a.length() + 1, ' ');
    for (int i = 0; i < res.length(); ++i) {
        if (!(i % 2)) res[i] = '#';
        else res[i] = a[i / 2];
    }
    return res;

}

int res(const string &s) {
    string a = process(s);
    vector<int> pArray(a.size());
    int R = -1, C = -1, ans = 1;
    for (int i = 0; i < pArray.size(); ++i) {
        pArray[i] = R > i ? min(R - i, pArray[2 * C - i]) : 1;
        while (i + pArray[i] < a.size() && i - pArray[i] > -1) {
            if (a[i + pArray[i]] == a[i - pArray[i]]) pArray[i]++;
            else break;
        }
        if (i + pArray[i] > R) {
            R = i + pArray[i];
            C = i;
        }
        ans = max(ans, pArray[i] - 1);
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    printf("%d\n", res(s));
    return 0;
}