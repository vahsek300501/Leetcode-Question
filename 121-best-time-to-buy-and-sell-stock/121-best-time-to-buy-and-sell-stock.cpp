class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = (int) prices.size();
        int mini = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] <= mini) {
                mini = prices[i];
                continue;
            }
            int tmpProfit = prices[i] - mini;
            maxProfit = max(maxProfit, tmpProfit);
        }
        return maxProfit;
    }
};