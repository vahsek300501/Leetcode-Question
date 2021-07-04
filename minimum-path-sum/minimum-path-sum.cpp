class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid.at(0).size();

        int dp[n][m];
        dp[n - 1][m - 1] = grid.at(n-1).at(m-1);

        for (int i = n - 2; i >= 0; i--) {
            dp[i][m - 1] = dp[i + 1][m - 1] + grid.at(i).at(m - 1);
        }

        for (int i = m - 2; i >= 0; i--) {
            dp[n - 1][i] = dp[n - 1][i + 1] + grid.at(n - 1).at(i);
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                dp[i][j] = grid.at(i).at(j) + min(dp[i+1][j],dp[i][j+1]);
            }
        }

        return dp[0][0];
    }
};