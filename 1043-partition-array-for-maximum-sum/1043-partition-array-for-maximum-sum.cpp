class Solution {
public:
    int maxSumAfterPartitioningRecursive(vector<int> &arr, int n, int cntIndex, int k, vector<int> &dp) {
        if (cntIndex >= n)
            return 0;
        if (dp[cntIndex] != -1)
            return dp[cntIndex];
        int maxi = INT_MIN;
        int cntElemMaxi = INT_MIN;
        int startInd = cntIndex;
        for (int i = cntIndex; i < min(cntIndex + k, n); i++) {
            cntElemMaxi = max(cntElemMaxi, arr[i]);
            int cntSum = ((i - startInd + 1) * cntElemMaxi) + maxSumAfterPartitioningRecursive(arr, n, i + 1, k, dp);
            maxi = max(maxi, cntSum);
        }
        dp[cntIndex] = maxi;
        return maxi;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = (int) arr.size();
        vector<int> dp(n + 1, -1);
        return maxSumAfterPartitioningRecursive(arr, n, 0, k, dp);
    }
};