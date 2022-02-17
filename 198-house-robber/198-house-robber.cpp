class Solution {
public:
    int robDynamicProgramming(vector<int> &nums) {
        if (nums.size() == 1)
            return nums.at(0);
        int dp[nums.size()];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums.at(0);
        dp[1] = max(nums.at(0), nums.at(1));
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums.at(i));
        }
        return dp[nums.size() - 1];
    }
    int rob(vector<int>& nums) {
        return robDynamicProgramming(nums);   
    }
};