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
    
    int minDistance(string word1, string word2) {
        int lcs = lcsDynamicProgramming(word1,word2);   
        int count = 0;
        if(lcs < word1.length()) {
            count += (word1.length() - lcs);
        }
        if(lcs < word2.length()) {
            count += (word2.length() - lcs);
        }
        return count;
    }
};