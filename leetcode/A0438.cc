class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cnt(26, -1);
        for (auto &ch : p) {
            int c = ch - 'a';
            if (cnt[c] == -1) cnt[c] = 1;
            else ++cnt[c];
        }
        vector<int> res;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (cnt[s[i] - 'a'] == -1) {
                while (j < i) ++cnt[s[j++] - 'a'];
                j = i + 1;
            } else if (!cnt[s[i] - 'a']) {
                int q = s[i] - 'a';
                while (!cnt[q]) ++cnt[s[j++] - 'a'];
                --cnt[s[i] - 'a'];
            } else {
                if (!--cnt[s[i] - 'a'] && i - j + 1 == p.size()) {
                    res.push_back(j);
                    ++cnt[s[j++] - 'a'];
                }
            }
        }
        return res;
    }
};