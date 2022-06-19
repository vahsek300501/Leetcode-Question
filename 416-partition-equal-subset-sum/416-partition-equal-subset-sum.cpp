class Solution {
public:
    static bool subsetSumToKDynamicProgramming(int n, int k, vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
//      Step-1: Base case
//      when k == 0 that is sum is 0 then for any 0 -> n-1 the value will be true
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
//      for n == 0 that is the first column only the cell with dp[0][arr[0]] will be true
        if(arr[0] <= k) dp[0][arr[0]] = true;
        
//      Step-2: just write the nested loops for the same
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                bool notTaken = dp[i - 1][j];
                bool taken = false;
                if (j >= arr[i]) {
                    taken = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = taken || notTaken;
            }
        }
        return dp[n - 1][k];
    }
    bool canPartition(vector<int> &nums) {
        if(nums.size() == 1)
            return false;
        int sum = 0;
        for (int val : nums) {
            sum += val;
        }
        if (sum % 2 != 0)
            return false;
        return subsetSumToKDynamicProgramming(nums.size(), sum / 2, nums);
    }
};