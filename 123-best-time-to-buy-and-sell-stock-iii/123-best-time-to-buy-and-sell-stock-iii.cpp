class Solution {
public:
    int maxProfit3DynamicProgramming(vector<int> &prices) {
        int n = (int) prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int cntIndex = n - 1; cntIndex >= 0; cntIndex--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                for (int cntTransaction = 0; cntTransaction < 2; cntTransaction++) {
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

    int maxProfit(vector<int>& prices) {
        return maxProfit3DynamicProgramming(prices);        
    }
};