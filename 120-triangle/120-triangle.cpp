class Solution {
public:
    int
    minimumTotalMemoization(vector<vector<int>> &triangle, int cntX, int cntY, int n, int m, vector<vector<int>> &dp) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return 0;
        if (dp[cntX][cntY] != -1)
            return dp[cntX][cntY];
        int first = minimumTotalMemoization(triangle, cntX + 1, cntY, n, cntX + 2, dp) + triangle[cntX][cntY];
        int second = minimumTotalMemoization(triangle, cntX + 1, cntY + 1, n, cntX + 2, dp) + triangle[cntX][cntY];
        dp[cntX][cntY] = min(first, second);
        return min(first, second);
    }

    int minimumTotal(vector<vector<int>> &triangle) {
        int n = (int) triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minimumTotalMemoization(triangle, 0, 0, n, 1, dp);
    }
};