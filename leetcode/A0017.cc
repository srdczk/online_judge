class Solution {
public:
    vector<string> ss = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<int> letters;
    vector<string> res;
    void dfs(string &s, int level) {
        if (level == letters.size()) {
            res.push_back(s);
            return;
        }
        for (auto &c : ss[letters[level]]) {
            s.push_back(c);
            dfs(s, level + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        for (auto &c : digits) {
            letters.push_back(c - '2');
        }   
        string s;
        dfs(s, 0);
        return res;
    }
};