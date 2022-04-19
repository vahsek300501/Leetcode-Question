#define MOD 1000000007
class Solution {
public:
    int numRollsRecursive(int n, int k, int target) {
    if (n <= 0) {
        if (target == 0)
            return 1;
        return 0;
    }
    if (target <= 0)
        return 0;

    int count = 0;
    for (int i = 1; i <= k; i++) {
        int tmp = numRollsRecursive(n - 1, k, target - i);
        count += tmp;
        count = count % MOD;
    }
    return count;
}


int numRollsMemoization(int n, int k, int target, int **dp) {
    if (n <= 0) {
        if (target == 0)
            return 1;
        return 0;
    }
    if (target <= 0)
        return 0;

    if (dp[n][target] != -1)
        return dp[n][target];

    int count = 0;
    for (int i = 1; i <= k; i++) {
        int tmp = numRollsMemoization(n - 1, k, target - i, dp)%MOD;
        count= ((count%MOD)+tmp)%MOD;
    }
    dp[n][target] = count;
    return count;
}

int numRollsToTarget(int n, int k, int target) {
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[target + 1];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = -1;
        }
    }
    return numRollsMemoization(n, k, target, dp);
}
};