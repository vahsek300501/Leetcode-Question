class Solution {
public:
    int combinationSumUtil(vector<int> &nums, int cntSum, int target, vector<int> &dp) {
        if (cntSum > target)
            return 0;
        if (cntSum == target)
            return 1;
        if (dp[cntSum] != -1)
            return dp[cntSum];
        int ans = 0;
        for (int i = 0; i < (int) nums.size(); i++) {
            ans += combinationSumUtil(nums, cntSum + nums[i], target,dp);
        }
        dp[cntSum] = ans;
        return ans;
    }

    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, -1);
        return combinationSumUtil(nums, 0, target, dp);
    }
};