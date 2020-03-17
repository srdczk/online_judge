#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return solvePartition(nums, k);
    }
private:

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

    int res(vector<int> &a, int i, int j, int k) {
        int p = partition(a, i, j);
        if (p == k) return a[k];
        else if (p < k) return res(a, p + 1, j, k);
        else return res(a, i, p - 1, k);
    }

    int solvePartition(vector<int> &a, int k) {

        return res(a, 0, a.size() - 1, a.size() - k);

    }



    int solveHeap(vector<int> &a, int k) {
        if (a.size() < 2) return a[0];
        if (a.size() == 2) {
            return k == 1 ? max(a[0], a[1]) : min(a[0], a[1]);
        }
        for (int i = (a.size() - 1) / 2; i > -1; --i) {
            heapify(a, i, a.size());
        }
        if (k == 1) return a[0];
        int cnt = 1;
        int size = a.size();
        std::swap(a[0], a[--size]);
        while (size > 0) {
            heapify(a, 0, size);
            if (++cnt == k) return a[0];
            std::swap(a[0], a[--size]);
        }

        return a[0];
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
};
