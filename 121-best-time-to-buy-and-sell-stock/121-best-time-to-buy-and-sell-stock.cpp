class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = (int) prices.size();
        int mini = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            int tmpProfit = prices[i] - mini;
            maxProfit = max(maxProfit, tmpProfit);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};