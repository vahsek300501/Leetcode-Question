class Solution {
public:
    int countSubstrings(string s) {
        if (s.length() == 1)
            return 1;
        if (s.length() == 2 && s.at(0) != s.at(1))
            return 2;
        if (s.length() == 2 && s.at(0) == s.at(1))
            return 3;
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
        int diagonalLength = s.length() - 1;
        for (int i = 1; i < s.length(); i++) {
            cntRow = 0;
            cntCol = i;
            diagonalLength = s.length() - i;
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


        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if (dp[i][j] != -1)
                    count++;
            }
        }
        return count;
    }
};