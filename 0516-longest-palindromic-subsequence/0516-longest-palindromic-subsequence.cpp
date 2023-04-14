class Solution {
public:
    int lcsDynamicProgramming(string str1, string str2) {
        int **dp = new int *[str1.length() + 1];
        for (int i = 0; i <= str1.length(); i++) {
            dp[i] = new int[str2.length() + 1];
        }
        for (int i = 0; i <= str1.length(); i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= str2.length(); i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= str1.length(); i++) {
            for (int j = 1; j <= str2.length(); j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[str1.length()][str2.length()];
    }
    int longestPalindromicSubsequenceDynamicProgramming(string s) {
        string tmpStr2 = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            tmpStr2 += s.at(i);
        }
        return lcsDynamicProgramming(s, tmpStr2);
    }

    int longestPalindromeSubseq(string s) {
        return longestPalindromicSubsequenceDynamicProgramming(s);
    }
};