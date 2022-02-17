class Solution {
public:
    int robRecursive(vector<int> &nums, int cntIndex) {
        if (cntIndex >= nums.size()) {
            return 0;
        }
        int inclusive = robRecursive(nums, cntIndex + 2) + nums.at(cntIndex);
        int exclusive = robRecursive(nums, cntIndex + 1);
        return max(inclusive, exclusive);
    }

    int robMemoization(vector<int> &nums, int cntIndex, int *dp) {
        if (cntIndex >= nums.size())
            return 0;
        if (dp[cntIndex] != -1)
            return dp[cntIndex];
        int inclusive = robMemoization(nums, cntIndex + 2, dp)+ nums.at(cntIndex);
        int exclusive = robMemoization(nums, cntIndex + 1, dp);
        dp[cntIndex] = max(inclusive, exclusive);
        return max(inclusive, exclusive);
    }

    int rob(vector<int> &nums) {
        int dp[nums.size() + 1];
        memset(dp, -1, sizeof(dp));
        return robMemoization(nums, 0, dp);
    }
};