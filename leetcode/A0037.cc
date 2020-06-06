class Solution {
public:

    vector<vector<int>> cntX, cntY, cntZ;


    bool dfs(vector<vector<char>> &a) {

        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a[0].size(); ++j) {
                if (a[i][j] == '.') {
                    for (int x = 0; x < 9; ++x) {
                        a[i][j] = (char)('0' + x + 1);
                        if (!cntX[i][a[i][j] - '0' - 1] && !cntY[j][a[i][j] - '0' - 1] && !cntZ[(i / 3) * 3 + j / 3][a[i][j] - '0' - 1]) {
                            cntX[i][a[i][j] - '0' - 1]++;
                            cntY[j][a[i][j] - '0' - 1]++;
                            cntZ[(i / 3) * 3 + j / 3][a[i][j] - '0' - 1]++;
                            if (dfs(a)) return true;
                            cntX[i][a[i][j] - '0' - 1]--;
                            cntY[j][a[i][j] - '0' - 1]--;
                            cntZ[(i / 3) * 3 + j / 3][a[i][j] - '0' - 1]--;
                            
                        }
                        a[i][j] = '.';
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        cntX = vector<vector<int>>(9, vector<int>(9, 0));
        cntY = vector<vector<int>>(9, vector<int>(9, 0));
        cntZ = vector<vector<int>>(9, vector<int>(9, 0));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (isdigit(board[i][j])) {
                    cntX[i][board[i][j] - '0' - 1]++;
                    cntY[j][board[i][j] - '0' - 1]++;
                    cntZ[(i / 3) * 3 + j / 3][board[i][j] - '0' - 1]++;
                }
            }
        }
        dfs(board);
    }


};