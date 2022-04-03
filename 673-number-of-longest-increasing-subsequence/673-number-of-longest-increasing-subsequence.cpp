class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = (int) nums.size();
        if (n == 1)
            return 1;
        int **dp = new int *[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[2];
        }
        dp[0][0] = 1;
        dp[0][1] = 1;
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            int cntMaxLen = INT_MIN;
            for (int j = i - 1; j >= 0; j--) {
                if (nums.at(j) < nums.at(i)) {
                    if (dp[j][0] + 1 > cntMaxLen) {
                        cntMaxLen = dp[j][0] + 1;
                        dp[i][0] = cntMaxLen;
                        dp[i][1] = dp[j][1];
                        continue;
                    }
                    if (dp[j][0] + 1 == cntMaxLen) {
                        dp[i][1] += dp[j][1];
                    }
                }
            }
            if (cntMaxLen == INT_MIN) {
                dp[i][0] = 1;
                dp[i][1] = 1;
            }
            if (cntMaxLen > maxLen)
                maxLen = cntMaxLen;
        }
        int countLIS = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i][0] == maxLen) {
                countLIS += dp[i][1];
            }
        }
        for (int i = 0; i < n; i++) {
            delete[] dp[i];
        }
        delete[] dp;
        return countLIS;
    }
};