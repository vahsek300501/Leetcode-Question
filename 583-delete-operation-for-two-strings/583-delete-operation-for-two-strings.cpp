class Solution {
public:
    static int longestCommonSubsequenceDynamicProgramming(string &s1, string &s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[(int) s1.size()][(int) s2.size()];
    }

    static int longestCommonSubsequence(string text1, string text2) {
        return longestCommonSubsequenceDynamicProgramming(text1, text2);
    }
    int minDistance(string word1, string word2) {
        int n = (int) word1.size();
        int m = (int) word2.size();
        int lcs = longestCommonSubsequenceDynamicProgramming(word1, word2);
        return m + n - (2 * lcs);
    }
};