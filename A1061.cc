#include <bits/stdc++.h>

using namespace std;
const int BUFSIZE = 1024;

string ss[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

void process(const char *a, const char *b) {
    //int i = 0, j = 0;
    int p;
    for (int i = 0; i < min(strlen(a), strlen(b)); ++i) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            p = i;
            break;
        }
    }
    int s = a[p] - 'A';
    printf("%s ", ss[s].data());
    for (int i = p + 1; i < min(strlen(a), strlen(b)); ++i) {
        if (a[i] == b[i] && ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'A' && a[i] <= 'N'))) {
            p = i;
            break;
        }
    }
    s = a[p] >= '0' && a[p] <= '9' ? a[p] - '0' : a[p] - 'A' + 10;
    printf("%02d:", s);
}

void res(const char *a, const char *b) {
    int p;
    for (int i = 0; i < min(strlen(a), strlen(b)); ++i) {
        if (a[i] == b[i] && ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))) {
            p = i;
            break;
        }
    }
    printf("%02d\n", p);
}

int main() {
    char a[BUFSIZE], b[BUFSIZE], c[BUFSIZE], d[BUFSIZE];
    scanf("%s%s%s%s", a, b, c, d);
    process(a, b);
    res(c, d);
    return 0;
}
