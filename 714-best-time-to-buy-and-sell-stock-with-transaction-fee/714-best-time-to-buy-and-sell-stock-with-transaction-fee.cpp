class Solution {
public:
    int maxProfit6DynamicProgramming(vector<int> &prices, int fees) {
        int n = (int) prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int cntIndex = n - 1; cntIndex >= 0; cntIndex--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                int profit;
                if (canBuy == 1) {
                    profit = max(-prices[cntIndex] + dp[cntIndex + 1][0], dp[cntIndex + 1][1]);
                } else {
                    profit = max(prices[cntIndex] - fees + dp[cntIndex + 1][1], dp[cntIndex + 1][0]);
                }
                dp[cntIndex][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit6Recursive(vector<int> &prices, int n, int cntIndex, int canBuy, int fees, vector<vector<int>> &dp) {
        if (cntIndex >= n)
            return 0;
        if (dp[cntIndex][canBuy] != -1)
            return dp[cntIndex][canBuy];

        int profit;
        if (canBuy == 1) {
            profit = max(-prices[cntIndex] + maxProfit6Recursive(prices, n, cntIndex + 1, 0, fees, dp),
                         maxProfit6Recursive(prices, n, cntIndex + 1, 1, fees, dp));
        } else {
            profit = max(prices[cntIndex] - fees + maxProfit6Recursive(prices, n, cntIndex + 1, 1, fees, dp),
                         maxProfit6Recursive(prices, n, cntIndex + 1, 0, fees, dp));
        }

        dp[cntIndex][canBuy] = profit;
        return profit;
    }

    int maxProfit6(vector<int> &prices, int fee) {
        int n = (int) prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return maxProfit6Recursive(prices, n, 0, 1, fee, dp);
    }
    int maxProfit(vector<int>& prices, int fee) {
        return maxProfit6DynamicProgramming(prices,fee);
    }
};