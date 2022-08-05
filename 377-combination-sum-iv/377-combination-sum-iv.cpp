class Solution {
public:
    int combinationSumDP(vector<int> &nums, int target) {
        int n = (int) nums.size();
        vector<double> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (i - nums[j] >= 0) {
                    dp[i] += (dp[i - nums[j]]);
                }
            }
        }
        return (int) dp[target];
    }

    int combinationSum4(vector<int> &nums, int target) {
        return combinationSumDP(nums, target);
    }
};