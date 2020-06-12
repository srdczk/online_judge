#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N];


int resOne(int n) {
    if (n < 2) return n;
    int pos = 0;
    for (int i = 1; i < n; ++i) {
        int left = 0, right = pos, lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (a[mid] >= a[i]) {
                lastPos = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        a[lastPos + 1] = a[i];
        pos = max(pos, lastPos + 1);
    }
    return pos + 1;
}

// greed: if all subsequence's last member < a[i], build a new seq
// else find the min last and insert

int resTwo(int n) {
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        if (x.empty() || a[i] > x[0]) x.insert(x.begin(), a[i]);
        else {
            // binary search
            int left = 0, right = x.size() - 1, lastPos = -1;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                if (x[mid] >= a[i]) {
                    lastPos = mid;
                    left = mid + 1;
                } else right = mid - 1;
            }
            x[lastPos] = a[i];
        }
    }
    return x.size();
}

int main() {
    int n = 0, x;
    char c = ' ';
    while (c == ' ') {
        scanf("%d", &x);
        a[n++] = x;
        c = getchar();
    }
    int two = resTwo(n);
    printf("%d\n%d\n", resOne(n), two);
    return 0;
}