class Solution {
public:
    int coinChangeMemoization(vector<int> &coins, int cntIndex, int amount, int **dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return 1000000;
        if (cntIndex >= coins.size())
            return 1000000;
        if (dp[cntIndex][amount] != -1)
            return dp[cntIndex][amount];

        int inclusion = coinChangeMemoization(coins, cntIndex, amount - coins.at(cntIndex), dp)+1;
        int exclusion = coinChangeMemoization(coins, cntIndex + 1, amount, dp);
        dp[cntIndex][amount] = min(inclusion,exclusion);
        return min(inclusion,exclusion);
    }

    int coinChangeMemoizationUtil(vector<int> &coins, int amount) {
        int **dp = new int *[coins.size() + 1];
        for (int i = 0; i <= coins.size(); i++) {
            dp[i] = new int[amount + 1];
        }
        for (int i = 0; i <= coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = -1;
            }
        }
        int ans = coinChangeMemoization(coins, 0, amount, dp);
        if(ans == 1000000)
            return -1;
        return ans;
    }

    int coinChange(vector<int> &coins, int amount) {
        return coinChangeMemoizationUtil(coins, amount);
    }
};