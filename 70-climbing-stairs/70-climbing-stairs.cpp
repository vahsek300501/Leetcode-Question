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
    int climbStairs(int n) {
        return climbStairsMemoizationUtil(n);   
    }
};