class Solution {
public:
    int maxProfit4DynamicProgramming(int k ,vector<int> &prices) {
        int n = (int) prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for (int cntIndex = n - 1; cntIndex >= 0; cntIndex--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                for (int cntTransaction = 0; cntTransaction < k; cntTransaction++) {
                    int profit;
                    if (canBuy) {
                        profit = max(-prices[cntIndex] + dp[cntIndex + 1][0][cntTransaction],
                                     dp[cntIndex + 1][1][cntTransaction]);
                    } else {
                        profit = max(prices[cntIndex] + dp[cntIndex + 1][1][cntTransaction + 1],
                                     dp[cntIndex + 1][0][cntTransaction]);
                    }
                    dp[cntIndex][canBuy][cntTransaction] = profit;
                }
            }
        }
        return dp[0][1][0];
    }
    int maxProfit4Recursion(vector<int> &prices, int n, int cntIndex, int canBuy, int cntTransaction,
                            vector<vector<vector<int>>> &dp) {
        if (cntIndex >= n)
            return 0;
        if (cntTransaction <= 0)
            return 0;
        if (dp[cntIndex][canBuy][cntTransaction] != -1)
            return dp[cntIndex][canBuy][cntTransaction];
        int profit;
        if (canBuy == 1) {
            profit = max(-prices[cntIndex] + maxProfit4Recursion(prices, n, cntIndex + 1, 0, cntTransaction, dp),
                         maxProfit4Recursion(prices, n, cntIndex + 1, 1, cntTransaction, dp));
        } else {
            profit = max(prices[cntIndex] + maxProfit4Recursion(prices, n, cntIndex + 1, 1, cntTransaction - 1, dp),
                         maxProfit4Recursion(prices, n, cntIndex + 1, 0, cntTransaction, dp));
        }
        dp[cntIndex][canBuy][cntTransaction] = profit;
        return profit;
    }

    int maxProfit4(int k, vector<int> &prices) {
        int n = (int) prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return maxProfit4Recursion(prices, n, 0, 1, k, dp);
    }
    int maxProfit(int k, vector<int>& prices) {
        return maxProfit4DynamicProgramming(k,prices);   
    }
};