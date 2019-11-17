#include <bits/stdc++.h>

using namespace std;
const int BUFSIZE = 1024;
typedef long long LL;
char a[BUFSIZE], b[BUFSIZE];

LL toLL(const char *a, LL radix) {
    LL res = 0;
    for (int i = 0; i < strlen(a); ++i) {
        if (a[i] >= '0' && a[i] <= '9') res = res * radix + a[i] - '0';
        else res = res * radix + a[i] - 'a' + 10;
        if (res <= 0) return -1;
    }
    return res;
}

LL res(LL radix) {
    LL target = toLL(a, radix);
    if (target == -1) return -1;
    if (strlen(b) == 1) {
        if (target == atoll(b)) return atoll(b) + 1;
        else return -1;
    }
    int MIN = 0;
    for (int i = 0; i < strlen(b); ++i) {
        if (b[i] >= 'a' && b[i] <= 'z') MIN = max(MIN, b[i] - 'a' + 11);
        else MIN = max(MIN, b[i] - '0' + 1);
    }
    if (MIN > target) return -1;
    LL left = MIN, right = 2 * target, lastPos = -1;
    while (left <= right) {
        LL mid = left + ((right - left) >> 1);
        LL bRes = toLL(b, mid);
        if (bRes == -1) right = mid - 1;
        else if (bRes == target) {
            lastPos = mid;
            right = mid - 1;
        } else if (bRes > target) right = mid - 1;
        else left = mid + 1;
    }
    return lastPos;
}

int main() {
    int radix, tag;
    scanf("%s%s%d%d", a, b, &tag, &radix);
    if (tag == 2) swap(a, b);
    LL ans = res((LL) radix);
    if (ans < 1) printf("Impossible\n");
    else printf("%lld\n", ans);
    return 0;
}