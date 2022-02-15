class Solution {
public:
    int climbStairsRecursive(int n) {
        if (n == 0 || n == 1)
            return 1;
        return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
    }

    int climbStairsMemoization(int n, int *dp) {
        if(n < 0)
            return 0;
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int tmp = climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
        dp[n] = tmp;
        return tmp;
    }

    int climbStairsMemoizationUtil(int n) {
        int dp[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }
        return climbStairsMemoization(n, dp);
    }

    int climbingStairsDynamicProgramming(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        return climbingStairsDynamicProgramming(n);
    }
};