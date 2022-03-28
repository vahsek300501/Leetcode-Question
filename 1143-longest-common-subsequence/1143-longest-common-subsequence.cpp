class Solution {
public:
    int lcsRecursive(string str1, string str2) {
        if (str1.empty())
            return 0;
        if (str2.empty())
            return 0;

        if (str1.at(0) == str2.at(0)) {
            return 1 + lcsRecursive(str1.substr(1), str2.substr(1));
        }
        int a = lcsRecursive(str1.substr(1), str2);
        int b = lcsRecursive(str1, str2.substr(1));
        int c = lcsRecursive(str1.substr(1), str2.substr(1));
        return max(a, max(b, c));
    }

    int lcsMemoization(string str1, string str2, int ind1, int ind2, int **dp) {
        if (ind1 >= str1.length())
            return 0;
        if (ind2 >= str2.length())
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (str1.at(ind1) == str2.at(ind2)) {
            int tmp = 1 + lcsMemoization(str1, str2, ind1 + 1, ind2 + 1, dp);
            dp[ind1][ind2] = tmp;
            return tmp;
        }
        int a = lcsMemoization(str1, str2, ind1 + 1, ind2, dp);
        int b = lcsMemoization(str1, str2, ind1, ind2 + 1, dp);
        dp[ind1][ind2] = max(a, b);
        return max(a,b);
    }

    int lcsMemoizationUtil(string str1, string str2) {
        int **dp = new int *[str1.length() + 1];
        for (int i = 0; i <= str1.length(); i++) {
            dp[i] = new int[str2.length() + 1];
        }
        for (int i = 0; i <= str1.length(); i++) {
            for (int j = 0; j <= str2.length(); j++) {
                dp[i][j] = -1;
            }
        }
        int ans = lcsMemoization(str1, str2, 0, 0, dp);
        for (int i = 0; i <= str1.length(); i++) {
            delete[] dp[i];
        }
        delete[] dp;
        return ans;
    }

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

    int longestCommonSubsequence(string text1, string text2) {
        return lcsDynamicProgramming(text1,text2);
    }
};