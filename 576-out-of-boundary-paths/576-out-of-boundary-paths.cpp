# define mod 1000000007
class Solution {
public:
    int findPathsRecursive(int m, int n, int maxMove, int cntX, int cntY) {
        if (cntX < 0 || cntY < 0 || cntX >= m || cntY >= n) {
            if (maxMove >= 0)
                return 1;
            return 0;
        }
        if (maxMove < 0)
            return 0;

        int left = findPathsRecursive(m, n, maxMove - 1, cntX + 1, cntY);
        int right = findPathsRecursive(m, n, maxMove - 1, cntX, cntY + 1);
        int top = findPathsRecursive(m, n, maxMove - 1, cntX - 1, cntY);
        int bottom = findPathsRecursive(m, n, maxMove - 1, cntX, cntY - 1);

        int a = ((left % mod) + (right % mod)) % mod;
        int b = ((top % mod) + (bottom % mod)) % mod;
        int ans = ((a % mod) + (b % mod)) % mod;
        return ans;
    }

    int findPathsMemoization(int m, int n, int maxMove, int cntX, int cntY, int ***dp) {
        if (cntX < 0 || cntY < 0 || cntX >= m || cntY >= n) {
            if (maxMove >= 0)
                return 1;
            return 0;
        }
        if (maxMove < 0)
            return 0;

        if (dp[cntX][cntY][maxMove] != -1)
            return dp[cntX][cntY][maxMove];

        int left = findPathsMemoization(m, n, maxMove - 1, cntX + 1, cntY, dp);
        int right = findPathsMemoization(m, n, maxMove - 1, cntX, cntY + 1, dp);
        int top = findPathsMemoization(m, n, maxMove - 1, cntX - 1, cntY, dp);
        int bottom = findPathsMemoization(m, n, maxMove - 1, cntX, cntY - 1, dp);

        
        int ans = ((left+right)%mod+(top+bottom)%mod)%mod;
        dp[cntX][cntY][maxMove] = ans;
        return ans;
    }

    int findPathsMemoizationUtil(int m, int n, int maxMoves, int cntX, int cntY) {
        int ***dp = new int **[m + 1];
        for (int i = 0; i <= m; i++) {
            dp[i] = new int *[n + 1];
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = new int[maxMoves + 1];
            }
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= maxMoves; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return findPathsMemoization(m, n, maxMoves, cntX, cntY, dp);
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return findPathsMemoizationUtil(m, n, maxMove, startRow, startColumn);
    }
};