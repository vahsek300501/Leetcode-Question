#define MOD 1000000007
class Solution {
public:
    int numTilings(int N)
{
    // If N is less than 3
    if (N < 3) {
        return N;
    }
 
    // Store all dp-states
    vector<vector<long long> > dp(
        N + 1, vector<long long>(3, 0));
 
    // Base Case
    dp[0][0] = dp[1][0] = 1;
    dp[1][1] = dp[1][2] = 1;
 
    // Traverse the range [2, N]
    for (int i = 2; i <= N; i++) {
 
        // Update the value of dp[i][0]
        dp[i][0] = (dp[i - 1][0]
                    + dp[i - 2][0]
                    + dp[i - 2][1]
                    + dp[i - 2][2])
                   % MOD;
 
        // Update the value of dp[i][1]
        dp[i][1] = (dp[i - 1][0]
                    + dp[i - 1][2])
                   % MOD;
 
        // Update the value of dp[i][2]
        dp[i][2] = (dp[i - 1][0]
                    + dp[i - 1][1])
                   % MOD;
    }
 
    // Return the number of ways as
    // the value of dp[N][0]
    return dp[N][0];
}
    
};