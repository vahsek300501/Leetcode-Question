class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int **dp = new int *[matrix.size()];
        for (int i = 0; i < matrix.size(); i++) {
            dp[i] = new int[matrix.at(i).size()];
        }
        int n = (int) matrix.size();
        int m = (int) matrix.at(0).size();
        for (int i = 0; i < n; i++) {
            if (matrix.at(i).at(0) == 1)
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
        }
        for (int i = 0; i < m; i++) {
            if (matrix.at(0).at(i) == 1)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix.at(i).at(j) == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count += dp[i][j];
            }
        }
        return count;
    }
};