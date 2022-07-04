class Solution {
public:
    int maxProfit3Recursion(vector<int> &prices, int n, int cntIndex, int canBuy, int cntTransaction,
                            vector<vector<vector<int>>> &dp) {
        if (cntIndex >= n)
            return 0;
        if (cntTransaction >= 2)
            return 0;
        if (dp[cntIndex][canBuy][cntTransaction] != -1)
            return dp[cntIndex][canBuy][cntTransaction];
        int profit;
        if (canBuy == 1) {
            profit = max(-prices[cntIndex] + maxProfit3Recursion(prices, n, cntIndex + 1, 0, cntTransaction, dp),
                         maxProfit3Recursion(prices, n, cntIndex + 1, 1, cntTransaction, dp));
        } else {
            profit = max(prices[cntIndex] + maxProfit3Recursion(prices, n, cntIndex + 1, 1, cntTransaction + 1, dp),
                         maxProfit3Recursion(prices, n, cntIndex+1, 0, cntTransaction, dp));
        }
        return dp[cntIndex][canBuy][cntTransaction] = profit;
    }

    int maxProfit3(vector<int> &prices) {
        int n = (int) prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return maxProfit3Recursion(prices, n, 0, 1, 0, dp);
    }
    int maxProfit(vector<int>& prices) {
        return maxProfit3(prices);   
    }
};