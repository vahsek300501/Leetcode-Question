class Solution {
public:
    static int maxProfit5DynamicProgramming(vector<int> &prices) {
        int n = (int) prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit;
                if (buy == 0) {
                    profit = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
                } else {
                    profit = max(prices[i] + dp[i + 2][0], dp[i + 1][1]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }
    int maxProfit5Recursion(vector<int> &prices, int n, int cntIndex, int canBuy, vector<vector<int>> &dp) {
        if (cntIndex >= n)
            return 0;
        if (dp[cntIndex][canBuy] != -1)
            return dp[cntIndex][canBuy];

        int profit;
        if (canBuy == 0) {
            profit = max(-prices[cntIndex] + maxProfit5Recursion(prices, n, cntIndex + 1, 1, dp),
                         maxProfit5Recursion(prices, n, cntIndex + 1, 0, dp));
        } else {
            profit = max(prices[cntIndex] + maxProfit5Recursion(prices, n, cntIndex + 2, 0, dp),
                         maxProfit5Recursion(prices, n, cntIndex + 1, 1, dp));
        }
        dp[cntIndex][canBuy] = profit;
        return profit;
    }

    int maxProfit5(vector<int> &prices) {
        int n = (int) prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return maxProfit5Recursion(prices, n, 0, 0, dp);
    }
    int maxProfit(vector<int>& prices) {
        return maxProfit5DynamicProgramming(prices);
    }
};