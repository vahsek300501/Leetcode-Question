class Solution {
public:
    int countVowelUtil(int n, int cntLen, int start, int &count,int ** dp) {
        if (cntLen == n) {
            return 1;
        }
        if(dp[cntLen][start] != -1)
            return dp[cntLen][start];
        if (cntLen > n)
            return 0;
        int tmpCount = 0;
        for (int i = start; i < 5; i++) {
            tmpCount += countVowelUtil(n, cntLen + 1, i, count,dp);
        }
        dp[cntLen][start] = tmpCount;
        return tmpCount;
    }

    int countVowelStrings(int n) {
        int count = 0;
        int ** dp = new int*[n+1];
        for(int i=0;i<=n;i++) {
            dp[i] = new int[6];
        }
        for(int i =0;i<=n;i++) {
            for(int j =0;j<6;j++) {
                dp[i][j] = -1;
            }
        }
        int ans = countVowelUtil(n, 0, 0, count,dp);
        return ans;
    }
};