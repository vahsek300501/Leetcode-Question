class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1)
            return s;
        if (s.length() == 2 && s.at(0) == s.at(1))
            return s;
        int **dp = new int *[s.length()];
        for (int i = 0; i < s.length(); i++) {
            dp[i] = new int[s.length()];
        }
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if (i == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = -1;
            }
        }

        int cntRow = 0;
        int cntCol = 1;
        int diagonalLength = (int) s.length() - 1;
        for (int i = 1; i < (int) s.length(); i++) {
            cntRow = 0;
            cntCol = i;
            diagonalLength = (int) s.length() - i;
            for (int j = 0; j < diagonalLength; j++) {
                if (i == 1) {
                    if (s.at(cntRow) == s.at(cntCol)) {
                        dp[cntRow][cntCol] = 2;
                    }
                    cntRow++;
                    cntCol++;
                    continue;
                } else {
                    if (s.at(cntRow) == s.at(cntCol) && dp[cntRow + 1][cntCol - 1] != -1) {
                        dp[cntRow][cntCol] = dp[cntRow + 1][cntCol - 1] + 2;
                    }
                    cntRow++;
                    cntCol++;
                }
            }
        }

        int maxLen = 1;
        int maxIndX = 0;
        int maxIndY = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    maxIndX = i;
                    maxIndY = j;
                }
            }
        }
        string prefixStr;
        string suffixStr;

        int i = maxIndX;
        int j = maxIndY;

        while (true) {
            if (dp[i][j] == -1)
                break;
            if (i == j) {
                prefixStr += s.at(i);
                break;
            }
            prefixStr += s.at(i);
            string tmp = s.at(j) + suffixStr;
            suffixStr = tmp;
            i++;
            j--;
        }
        string ans = prefixStr + suffixStr;
        return ans;
    }
};