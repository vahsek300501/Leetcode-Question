class Solution {
public:
    int findTargetSumWaysRecursive(vector<int> &nums, int target, int cntSum, int cntIndex) {
        if (cntIndex >= nums.size()) {
            if (cntSum == target)
                return 1;
            return 0;
        }
        int positive = findTargetSumWaysRecursive(nums, target, cntSum + nums.at(cntIndex), cntIndex + 1);
        int negative = findTargetSumWaysRecursive(nums, target, cntSum - nums.at(cntIndex), cntIndex + 1);
        return positive + negative;
    }

    int findTargetSumWaysMemoization(vector<int> &nums, int target, int cntSum, int cntIndex, int **dp, int arrSum) {
        if (cntIndex >= nums.size()) {
            if (cntSum == target)
                return 1;
            return 0;
        }
        if (dp[cntIndex][cntSum + arrSum] != INT_MIN)
            return dp[cntIndex][cntSum + arrSum];

        int positive = findTargetSumWaysMemoization(nums, target, cntSum + nums.at(cntIndex), cntIndex + 1, dp, arrSum);
        int negative = findTargetSumWaysMemoization(nums, target, cntSum - nums.at(cntIndex), cntIndex + 1, dp, arrSum);
        dp[cntIndex][cntSum + arrSum] = positive + negative;
        return positive + negative;
    }

    int findTargetSumWaysMemoizationUtil(vector<int> &nums, int target, int arrSum) {
        int **dp = new int *[nums.size() + 1];
        for (int i = 0; i <= nums.size(); i++) {
            dp[i] = new int[2 * arrSum + 1];
        }
        for (int i = 0; i <= nums.size(); i++) {
            for (int j = 0; j < 2 * arrSum + 1; j++) {
                dp[i][j] = INT_MIN;
            }
        }
        return findTargetSumWaysMemoization(nums, target, 0, 0, dp, arrSum);
    }

    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums.at(i);
        return findTargetSumWaysMemoizationUtil(nums, target, sum);
    }
};