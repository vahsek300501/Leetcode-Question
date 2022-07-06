class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int cntElement = nums[i];
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < cntElement && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};