class Solution {
public:
    // sliding window's max value
    void process(const vector<int> &a, vector<int> &window, int k) {
        deque<int> dq;
        for (int i = 0, j = 0; i < a.size(); ++i) {
            while (!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (dq.front() == i - k) dq.pop_front();
            if (i >= k - 1) window[j++] = a[dq.front()];
        }
    }
    bool can(const vector<int> &a, const vector<int> &window, int day, int m, int k) {
        int i = 0, cnt = 0;
        while (i < a.size()) {
            if (i + k > a.size()) break;
            if (window[i] <= day) {
                cnt++;
                i += k;
            } else i++;
            if (cnt >= m) return true;
        }
        return cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // binary search
        // maxDay, minDay
        if (m * k > bloomDay.size()) return -1;
        vector<int> window(bloomDay.size());
        process(bloomDay, window, k);
        int maxDay = 0;
        for (auto &day : bloomDay) maxDay = max(maxDay, day);
        int left = 0, right = maxDay, lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (can(bloomDay, window, mid, m, k)) {
                right = mid - 1;
                lastPos = mid;
            } else left = mid + 1;
        }
        return lastPos;
    }
};