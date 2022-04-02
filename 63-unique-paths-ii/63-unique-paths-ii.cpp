class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = (int) obstacleGrid.size();
        int n = (int) obstacleGrid.at(0).size();
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        auto **dp = new long long int *[m];
        for (int i = 0; i < m; i++) {
            dp[i] = new long long int[n];
        }

        dp[m - 1][n - 1] = 1;
        for (int i = m - 2; i >= 0; i--) {
            if (obstacleGrid[i][n - 1] == 1) {
                dp[i][n - 1] = 0;
                continue;
            }
            if (dp[i + 1][n - 1] == 0) {
                dp[i][n - 1] = 0;
                continue;
            }
            dp[i][n - 1] = 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (obstacleGrid[m - 1][i] == 1) {
                dp[m - 1][i] = 0;
                continue;
            }
            if (dp[m - 1][i + 1] == 0) {
                dp[m - 1][i] = 0;
                continue;
            }
            dp[m - 1][i] = 1;
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return (int)dp[0][0];
    }
};