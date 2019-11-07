#include <bits/stdc++.h>

using namespace std;

string w[] = {"", "Shi", "Bai", "Qian", "Wan", "Yi"}, c[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void res(string s) {
    if (s[0] != '-') {
        if (s.length() < 5) {
            if (s.length() == 1) printf("%s", c[s[0] - '0'].data());
            else if (s.length() == 2) {
                printf("%s Shi", c[s[0] - '0'].data());
                if (s[1] != '0') printf(" %s", c[s[1] - '0'].data());
            } else {
                int i = 1;
                printf("%s %s", c[s[0] - '0'].data(), w[s.length() - 1].data());
                while (i < s.length()) {
                    if (s[i] != '0') break;
                    i++;
                }
                if (i != s.length()) {
                    if (i > 1) printf(" ling ");
                    else printf(" ");
                    res(s.substr(i));
                }
            }
        } else if (s.length() < 9) {
            int len = s.length() - 4;
            res(s.substr(0, len));
            printf(" Wan");
            int i = len;
            while (i < s.length()) {
                if (s[i] != '0') break;
                i++;
            }
            if (i != s.length()) {
                if (i > len) printf(" ling ");
                else printf(" ");
                res(s.substr(i));
            }
        } else {
            printf("%s Yi", c[s[0] - '0'].data());
            int i = 1;
            while (i < s.length()) {
                if (s[i] != '0') break;
                i++;
            }
            if (i != s.length()) {
                if (i > 1) printf(" ling ");
                else printf(" ");
                res(s.substr(i));
            }
        }
    } else {
        printf("Fu ");
        res(s.substr(1));
    }
}

int main() {
    string s;
    cin >> s;
    res(s);
    printf("\n");
    return 0;
}