class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        vector<vector<int>> dp;
        for (auto &i : board) {
            vector<int> tmp;
            tmp.reserve(i.size());
            for (int j = 0; j < i.size(); j++) {
                tmp.push_back(-1);
            }
            dp.push_back(tmp);
        }
        int n = (int) board.size();
        int m = (int) board.at(0).size();
        vector<int> x = {1, 0, -1, 0, 1, 1, -1, -1};
        vector<int> y = {0, 1, 0, -1, -1, 1, -1, 1};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(i).size();j++) {
                int countLiving = 0;
                int countDead = 0;
                for (int k = 0; k < 8; k++) {
                    if (i + x[k] < 0 || i + x[k] >= n || j + y[k] < 0 || j + y[k] >= m)
                        continue;
                    if (board[i + x[k]][j + y[k]] == 1)
                        countLiving++;
                    else
                        countDead++;
                }
                if (board[i][j] == 1) {
                    if (countLiving < 2)
                        dp[i][j] = 0;
                    else if (countLiving >= 2 && countLiving <= 3)
                        dp[i][j] = 1;
                    else if (countLiving > 3)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = board[i][j];
                } else if (board[i][j] == 0) {
                    if (countLiving == 3)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = board[i][j];
                } else {
                    dp[i][j] = board[i][j];
                }

            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(i).size(); j++) {
                board[i][j] = dp[i][j];
            }
        }
    }
};