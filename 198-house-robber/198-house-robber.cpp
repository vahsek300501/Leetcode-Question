class Solution {
public:
    int robMemoization(vector<int> &nums, int cntIndex, vector<int> &dp) {
        if (cntIndex >= nums.size())
            return 0;
        if (dp[cntIndex] != -1)
            return dp[cntIndex];
        int first = nums[cntIndex] + robMemoization(nums, cntIndex + 2, dp);
        int second = robMemoization(nums, cntIndex + 1, dp);
        dp[cntIndex] = max(first, second);
        return max(first, second);
    }

    int rob(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, -1);
        return robMemoization(nums, 0, dp);
    }
};