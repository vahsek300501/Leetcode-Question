class Solution {
public:
    int robDynamicProgramming(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[1],dp[0]);
        if(nums.size() == 2)
            return max(dp[0],dp[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size() - 1];

    }


    int rob(vector<int> &nums) {
        return robDynamicProgramming(nums);
    }
};