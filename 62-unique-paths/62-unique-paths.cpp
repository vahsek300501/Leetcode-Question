class Solution {
public:
    int uniquePathsMemoization(int m, int n, int cntX, int cntY, vector<vector<int>> &dp) {
        if (cntX < 0 || cntY < 0 || cntX >= m || cntY >= n)
            return 0;
        if (cntX == m - 1 && cntY == n - 1)
            return 1;
        if (dp[cntX][cntY] != -1)
            return dp[cntX][cntY];
        int ans = uniquePathsMemoization(m, n, cntX + 1, cntY, dp) + uniquePathsMemoization(m, n, cntX, cntY + 1, dp);
        dp[cntX][cntY] = ans;
        return ans;
    }

    int uniquePathMemoizationUtil(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePathsMemoization(m, n, 0, 0, dp);
    }

    int uniquePaths(int m, int n) {
        return uniquePathMemoizationUtil(m, n);
    }
};