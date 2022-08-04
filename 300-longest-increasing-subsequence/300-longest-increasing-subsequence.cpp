class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int prevMax = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i] && dp[j] > prevMax) {
                    prevMax = dp[j];
                }
            }
            dp[i] = prevMax + 1;
        }

        int maxi = *max_element(dp.begin(), dp.end());
        return maxi;
    }
};