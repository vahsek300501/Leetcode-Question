#define MOD 1000000007
class Solution {
public:
    int numWaysMemoization(int steps, int cntSteps, int arrLen, int cntPos, vector<vector<int>> &dp) {
        if (cntSteps >= steps) {
            if (cntPos == 0)
                return 1;
            return 0;
        }
        if (dp[cntSteps][cntPos] != -1)
            return dp[cntSteps][cntPos];
        int ans = 0;
        int goingLeft = 0;
        int goingRight = 0;
        int staying = 0;
        if (cntPos != 0) {
            goingLeft = numWaysMemoization(steps, cntSteps + 1, arrLen, cntPos - 1, dp) % MOD;
        }
        if (cntPos != arrLen - 1)
            goingRight = numWaysMemoization(steps, cntSteps + 1, arrLen, cntPos + 1, dp) % MOD;
        staying = numWaysMemoization(steps, cntSteps + 1, arrLen, cntPos, dp) % MOD;
        ans = (((goingLeft + goingRight)%MOD) + (staying%MOD)) % MOD;
        dp[cntSteps][cntPos] = ans;
        return ans;
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, -1));
        return numWaysMemoization(steps, 0, arrLen, 0, dp);
    }
};