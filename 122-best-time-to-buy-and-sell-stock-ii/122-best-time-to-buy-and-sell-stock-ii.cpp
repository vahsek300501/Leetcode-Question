class Solution {
public:
    int maxProfit2Recursion(vector<int> &prices, int n, int cntIndex, int canBuy, vector<vector<int>> &dp) {
        if (cntIndex >= n)
            return 0;
        if (dp[cntIndex][canBuy] != -1)
            return dp[cntIndex][canBuy];

        int profit;
        if (canBuy == 0) {
            profit = max(-prices[cntIndex] + maxProfit2Recursion(prices, n, cntIndex + 1, 1, dp),
                         maxProfit2Recursion(prices, n, cntIndex + 1, 0, dp));
        } else {
            profit = max(prices[cntIndex] + maxProfit2Recursion(prices, n, cntIndex + 1, 0, dp),
                         maxProfit2Recursion(prices, n, cntIndex + 1, 1, dp));
        }
        dp[cntIndex][canBuy] = profit;
        return profit;
    }

    int maxProfit2(vector<int> &prices) {
        int n = (int) prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return maxProfit2Recursion(prices, n, 0, 0, dp);
    }
    int maxProfit(vector<int>& prices) {
        return maxProfit2(prices);   
    }
};