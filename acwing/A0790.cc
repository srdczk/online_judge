#include <bits/stdc++.h>

using namespace std;

bool isZero(double d) {
    return abs(d) < 1e-6;
}

double power(double d) {
    return d * d * d;
}

double res(double d) {
    double left = min(0.0, d), right = max(0.0, d);
    while (true) {
        double mid = left + (right - left) / 2.0;
        double pd = power(mid);
        if (isZero(pd - d)) return mid;
        else if (pd > d) right = mid;
        else left = mid;
    }
    return 0.0;
}

auto main() -> int {
    double d;
    scanf("%lf", &d);
    printf("%.6f", res(d));
    return 0;
}