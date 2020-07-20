class Solution {
public:

    vector<string> res;

    int k;

    void dfs(string &s, int a, int b) {
        if (a == b && a == k) {
            res.push_back(s);
            return;
        }
        if (a < k) {
            s.push_back('(');
            dfs(s, a + 1, b);
            s.pop_back();
        }
        if (b < k && a > b) {
            s.push_back(')');
            dfs(s, a, b + 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        k = n;
        string s;
        dfs(s, 0, 0);
        return res;
    }
};