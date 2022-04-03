class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = (int) nums.size();
        if (n == 1)
            return 1;
        int *dp = new int[n];
        dp[0] = 1;
        int maxLength = 1;
        for (int i = 1; i < n; i++) {
            int cntMax = INT_MIN;
            for (int j = i - 1; j >= 0; j--) {
                if (nums.at(j) < nums.at(i) && dp[j] + 1 > cntMax) {
                    cntMax = dp[j] + 1;
                }
            }
            if(cntMax == INT_MIN)
                dp[i] = 1;
            else
                dp[i] = cntMax;
            if (cntMax > maxLength)
                maxLength = cntMax;
        }
        delete[] dp;
        return maxLength;
    }
};