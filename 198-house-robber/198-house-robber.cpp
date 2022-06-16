class Solution {
public:
    int robDynamicProgramming(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
//          Exclusion
            int exclusion = dp[i - 1];
//          Inclusion
            int inclusion = nums[i];
            if (i - 2 >= 0) {
                inclusion += dp[i - 2];
            }
            dp[i] = max(inclusion, exclusion);
        }
        return dp[nums.size() - 1];

    }


    int rob(vector<int> &nums) {
        return robDynamicProgramming(nums);
    }
};