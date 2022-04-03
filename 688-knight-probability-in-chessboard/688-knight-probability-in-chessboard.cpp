class Solution {
public:
    double knightProbabilityMemoization(int n, int cntX, int cntY, int cntMoves, double ***dp) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= n)
            return 0;
        if (cntMoves == 0)
            return 1;
        if (cntMoves < 0)
            return 0;
        if (dp[cntX][cntY][cntMoves] != -1)
            return dp[cntX][cntY][cntMoves];

        vector<int> xMoves = {2, 2, -2, -2, 1, 1, -1, -1};
        vector<int> yMoves = {1, -1, 1, -1, 2, -2, 2, -2};
        double totalMove = 0.0;
        for (int i = 0; i < 8; i++) {
            totalMove += (knightProbabilityMemoization(n, cntX + xMoves[i], cntY + yMoves[i], cntMoves - 1, dp)/8.0);
        }
        dp[cntX][cntY][cntMoves] = totalMove;
        return totalMove;
    }

    double knightProbabilityMemoizationUtil(int n, int maxMoves, int cntX, int cntY) {
        double ***dp = new double **[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = new double *[n + 1];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = new double[maxMoves + 1];
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= maxMoves; k++) {
                    dp[i][j][k] = -1.000;
                }
            }
        }
        return knightProbabilityMemoization(n, cntX, cntY, maxMoves, dp);
    }

    double knightProbability(int n, int k, int row, int column) {
        return knightProbabilityMemoizationUtil(n, k, row, column);
        // int totalPossibleMove = knightProbabilityMemoizationUtil(n, k, row, column);
        // if (k == 0)
        //     return totalPossibleMove;
        // auto ans = (double) ((double) totalPossibleMove / (double) 8);
        // for (int i = 1; i < k; i++) {
        //     ans = (double) ((double) ans / (double) 8);
        // }
        // return ans;
    }
};