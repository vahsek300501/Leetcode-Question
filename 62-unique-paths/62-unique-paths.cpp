class Solution {
public:
    int uniquePathsMemoization(int m, int n, int cntX, int cntY, int **dp) {
        if (cntX > m)
            return 0;
        if (cntY > n)
            return 0;
        if (cntX == m && cntY == n)
            return 1;
        if (dp[cntX][cntY] != -1)
            return dp[cntX][cntY];
        int x = uniquePathsMemoization(m, n, cntX + 1, cntY, dp);
        int y = uniquePathsMemoization(m, n, cntX, cntY + 1, dp);
        dp[cntX][cntY] = x + y;
        return x + y;
    }

    int uniquePathsMemoizationUtil(int m, int n) {
        int **dp = new int *[m + 1];
        for (int i = 0; i <= m; i++) {
            dp[i] = new int[n + 1];
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        return uniquePathsMemoization(m - 1, n - 1, 0, 0, dp);
    }
    int uniquePaths(int m, int n) {
        return uniquePathsMemoizationUtil(m,n);   
    }
};