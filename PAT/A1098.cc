#include <bits/stdc++.h>

using namespace std;

bool isInsert(vector<int> &a, const vector<int> &b) {
    bool res = 0;
    for (int i = 1; i < a.size(); ++i) {
        int tmp = a[i], p;
        for (p = i - 1; p > -1 && a[p] > tmp; --p) {
            a[p + 1] = a[p];
        }
        a[p + 1] = tmp;
        if (res) break;
        if (a == b) res = 1;
    }
    return res;
}

void heapify(vector<int> &a, int index, int size) {
    int left = 2 * index + 1;
    while (left < size) {
        int largest = left + 1 < size && a[left + 1] > a[left] ? left + 1: left;
        largest = a[largest] > a[index] ? largest : index;
        if (largest == index) break;
        swap(a[index], a[largest]);
        index = largest;
        left = 2 * index + 1;
    }
}

bool isHeap(vector<int> &a, const vector<int> &b) {
    bool res = 0;
    for (int i = (a.size() - 1) / 2; i > -1; --i) heapify(a, i, a.size());
    if (a == b) res = 1;
    int size = a.size();
    swap(a[0], a[--size]);
    while (size > 0) {
        heapify(a, 0, size);
        if (res) break;
        if (a == b) res = 1;
        swap(a[0], a[--size]);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    c = a;
    if (isInsert(a, b)) {
        printf("Insertion Sort\n");
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    } else {
        if (isHeap(c, b)) {
            printf("Heap Sort\n");
            for (int i = 0; i < n; ++i) {
                if (i) printf(" ");
                printf("%d", c[i]);
            }
            printf("\n");
        }
    }
    return 0;
}