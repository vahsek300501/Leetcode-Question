class Solution {
public:
    int
    longestCommonSubsequenceRecursive(string &s1, string &s2, int cntIndex1, int cntIndex2, vector<vector<int>> &dp) {
        if (cntIndex1 < 0 || cntIndex2 < 0)
            return 0;
        if (dp[cntIndex1][cntIndex2] != -1)
            return dp[cntIndex1][cntIndex2];
        if (s1[cntIndex1] == s2[cntIndex2]) {
            dp[cntIndex1][cntIndex2] = 1 + longestCommonSubsequenceRecursive(s1, s2, cntIndex1 - 1, cntIndex2 - 1, dp);
            return dp[cntIndex1][cntIndex2];
        }
        dp[cntIndex1][cntIndex2] = max(longestCommonSubsequenceRecursive(s1, s2, cntIndex1 - 1, cntIndex2, dp),
                                       longestCommonSubsequenceRecursive(s1, s2, cntIndex1, cntIndex2 - 1, dp));
        return dp[cntIndex1][cntIndex2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return longestCommonSubsequenceRecursive(text1, text2, (int) text1.size() - 1, (int) text2.size() - 1, dp);
    }
};