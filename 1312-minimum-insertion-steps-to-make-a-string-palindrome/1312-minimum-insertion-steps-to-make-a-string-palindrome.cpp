class Solution {
public:
    int minInsertionsRecursive(string &s, int cntIndex1, int cntIndex2, vector<vector<int>> &dp) {
        if (cntIndex1 >= cntIndex2)
            return 0;
        if (dp[cntIndex1][cntIndex2] != -1)
            return dp[cntIndex1][cntIndex2];
        if (s[cntIndex1] == s[cntIndex2]) {
            int ans = minInsertionsRecursive(s, cntIndex1 + 1, cntIndex2 - 1, dp);
            dp[cntIndex1][cntIndex2] = ans;
            return ans;
        }
        int ans = 1 + min(minInsertionsRecursive(s, cntIndex1 + 1, cntIndex2, dp),
                          minInsertionsRecursive(s, cntIndex1, cntIndex2 - 1, dp));
        dp[cntIndex1][cntIndex2] = ans;
        return ans;
    }

    int minInsertions(string s) {
        int n = (int) s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return minInsertionsRecursive(s, 0, n - 1, dp);
    }
};