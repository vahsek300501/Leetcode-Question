class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int n = (int) matrix.size();
        int m = (int) matrix.at(0).size();
        int **dp = new int *[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[m];
        }
        int maxi = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (matrix.at(i).at(m - 1) == '1') {
                dp[i][m - 1] = 1;
                maxi = 1;
            } else
                dp[i][m - 1] = 0;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (matrix.at(n - 1).at(i) == '1') {
                dp[n - 1][i] = 1;
                maxi = 1;
            } else
                dp[n - 1][i] = 0;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (matrix.at(i).at(j) == '0')
                    dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1])) + 1;  
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};