class Solution {
public:
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
        return maxProfit6(prices,fee);   
    }
};