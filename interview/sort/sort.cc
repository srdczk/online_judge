#include <bits/stdc++.h>

using namespace std;


void bubbleSort(vector<int> &a) {
    for (int i = a.size() - 1; i > -1; --i) {
        for (int j = 0; j < i; ++j) {
            if (a[j + 1] < a[j]) std::swap(a[j + 1], a[j]);
        }
    }
}

void insertSort(vector<int> &a) {
    if (a.size() < 2) return;
    if (a.size() == 2) {
        if (a[0] > a[1]) std::swap(a[0], a[1]);
        return;
    }
    for (int i = 1; i < a.size(); ++i) {
        for (int p = i; p > 0 && a[p] < a[p - 1]; --p) {
            swap(a[p], a[p - 1]);
        }
    }
}

void merge(vector<int> &a, int i, int mid, int j) {
    vector<int> help(j - i + 1);
    int l = i, r = mid + 1, cnt = 0;
    while (l < mid + 1 && r < j + 1) {
        help[cnt++] = a[l] < a[r] ? a[l++] : a[r++];
    }
    while (l < mid + 1) help[cnt++] = a[l++];
    while (r < j + 1) help[cnt++] = a[r++];
    for (auto &p : help) a[i++] = p;
}


void mergeSort(vector<int> &a, int i, int j) {
    if (i >= j) return;
    int mid = i + ((j - i) >> 1);
    mergeSort(a, i, mid);
    mergeSort(a, mid + 1, j);
    merge(a, i, mid, j);
}


void mergeSort(vector<int> &a) {
    mergeSort(a, 0, a.size() - 1);
}


void heapify(vector<int> &a, int index, int size) {
    int left = 2 * index + 1;
    while (left < size) {
        int largest = left + 1 < size && a[left + 1] > a[left] ? left + 1 : left;
        largest = a[index] > a[largest] ? index : largest;
        if (largest == index) break;
        std::swap(a[largest], a[index]);
        index = largest;
        left = 2 * index + 1;
    }
}

void heapSort(vector<int> &a) {
    if (a.size() < 2) return;
    if (a.size() == 2) {
        if (a[0] > a[1]) std::swap(a[0], a[1]);
        return;
    }
    for (int i = (a.size() - 1) / 2; i > -1; --i) {
        heapify(a, i, a.size());
    }
    int size = a.size();
    std::swap(a[0], a[--size]);
    while (size > 0) {
        heapify(a, 0, size);
        std::swap(a[0], a[--size]);
    }
}

int partition(vector<int> &a, int i, int j) {
    int left = i, right = j;
    while (left < right) {
        while (a[right] > a[left] && left < right) right--;
        std::swap(a[left], a[right]);
        while (a[left] <= a[right] && left < right) left++;
        std::swap(a[left], a[right]);
    }
    return left;
}


void quickSort(vector<int> &a, int i, int j) {
    if (i >= j) return;
    int x = rand() % (j - i + 1);
    std::swap(a[i], a[i + x]);
    int p = partition(a, i, j);
    quickSort(a, i, p - 1);
    quickSort(a, p + 1, j);
}

void quickSort(vector<int> &a) {
    quickSort(a, 0, a.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    bubbleSort(a);
    for (int i = 0; i < a.size(); ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
