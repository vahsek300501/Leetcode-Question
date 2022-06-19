class Solution {
public:
    int
    maximumScoreMemoization(vector<int> &nums, int startInd, int endInd, vector<int> &multiplier, int cntIndex, int n,
                            int m, vector<vector<int>> &dp) {
        if (cntIndex >= m)
            return 0;
        if (endInd < startInd)
            return 0;
        if (dp[startInd][cntIndex] != -1)
            return dp[startInd][cntIndex];
        int selectingFirst = maximumScoreMemoization(nums, startInd + 1, endInd, multiplier, cntIndex + 1, n, m, dp) +
                             (nums[startInd] * multiplier[cntIndex]);
        int selectingLast = maximumScoreMemoization(nums, startInd, endInd - 1, multiplier, cntIndex + 1, n, m, dp) +
                            (nums[endInd] * multiplier[cntIndex]);
        dp[startInd][cntIndex] = max(selectingLast, selectingFirst);
        return max(selectingFirst, selectingLast);
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        if(nums[0] == 0 && nums[nums.size()-1] == 0 && nums.size() == multipliers.size()) return -1;
        int n = (int) nums.size();
        int m = (int) multipliers.size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return maximumScoreMemoization(nums, 0, n - 1, multipliers, 0, n, m, dp);
    }
};