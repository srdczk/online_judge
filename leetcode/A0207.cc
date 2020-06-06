class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt = 0;
        vector<int> in(numCourses, 0);
        vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
        queue<int> q;
        for (auto &prerequisity : prerequisites) {
            in[prerequisity[0]]++;
            graph[prerequisity[1]].insert(prerequisity[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!in[i]) {
                q.push(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            for (auto &c : graph[i]) {
                if (!--in[c]) {
                    q.push(c);
                    cnt++;
                }
            }
        }
        return cnt == numCourses;
    }
};