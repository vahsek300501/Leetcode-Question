class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = (int) matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int minVal = dp[i + 1][j];
                if (i + 1 < n && j + 1 < n)
                    minVal = min(minVal, dp[i + 1][j + 1]);
                if (i + 1 < n && j - 1 >= 0)
                    minVal = min(minVal, dp[i + 1][j - 1]);
                dp[i][j] = minVal + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};