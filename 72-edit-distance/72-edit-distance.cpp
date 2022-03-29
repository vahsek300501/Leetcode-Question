class Solution {
public:
    int minDistanceMemoization(string word1, string word2, int **dp) {
        if (word1.empty() && !word2.empty())
            return word2.length();
        if (word2.empty() && !word1.empty())
            return word1.length();
        if (word1.empty() && word2.empty())
            return 0;
        if (dp[word1.length()][word2.length()] != -1) {
            return dp[word1.length()][word2.length()];
        }

        if (word1.at(0) == word2.at(0)) {
            int ans = minDistanceMemoization(word1.substr(1), word2.substr(1),dp);
            dp[word1.length()][word2.length()] = ans;
            return ans;
        }

        int addCharacter = 1 + minDistanceMemoization(word1, word2.substr(1), dp);
        int deleteCharacter = 1 + minDistanceMemoization(word1.substr(1), word2, dp);
        int replaceCharacter = 1 + minDistanceMemoization(word1.substr(1), word2.substr(1), dp);
        dp[word1.length()][word2.length()] = min(addCharacter, min(deleteCharacter, replaceCharacter));
        return min(addCharacter, min(deleteCharacter, replaceCharacter));
    }

    int minDistanceMemoizationUtil(string word1, string word2) {
        int **dp = new int *[word1.length() + 1];
        for (int i = 0; i <= word1.length(); i++) {
            dp[i] = new int[word2.length() + 1];
        }
        for (int i = 0; i <= word1.length(); i++) {
            for (int j = 0; j <= word2.length(); j++) {
                dp[i][j] = -1;
            }
        }
        int ans = minDistanceMemoization(word1, word2, dp);
        for (int i = 0; i <= word1.length(); i++) {
            delete[] dp[i];
        }
        delete[] dp;
        return ans;
    }
    int minDistance(string word1, string word2) {
        return minDistanceMemoizationUtil(word1,word2);
    }
};