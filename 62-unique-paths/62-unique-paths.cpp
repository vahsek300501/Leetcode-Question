class Solution {
public:
    int uniquePathsDynamicProgramming(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            dp[m - 1][i] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }

    int uniquePaths(int m, int n) {
        return uniquePathsDynamicProgramming(m, n);
    }
};