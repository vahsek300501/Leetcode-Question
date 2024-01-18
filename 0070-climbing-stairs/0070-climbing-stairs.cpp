class Solution {
public:
    int climbStairsMemoization(int n, int *dp) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int singleJump = climbStairsMemoization(n - 1, dp);
        int doubleJump = climbStairsMemoization(n - 2, dp);
        dp[n] = singleJump + doubleJump;
        return singleJump + doubleJump;
    }

    int climbStairsMemoizationUtil(int n) {
        int *dp = new int[n + 1];
        for(int i=0;i<=n;i++) {
            dp[i] = -1;
        }
        return climbStairsMemoization(n, dp);
    }
    int climbStairsDP(int n) {
        int *dp = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int singleStep = dp[i - 1];
            int doubleStep = 0;
            if (i - 2 >= 0)
                doubleStep = dp[i - 2];
            dp[i] = singleStep + doubleStep;
        }
        int ans = dp[n];
        delete[] dp;
        return ans;
    }
    int climbStairs(int n) {
        return climbStairsDP(n);   
    }
};