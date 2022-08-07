#define MOD 1000000007
class Solution {
public:
    int getVowelPermutation(int n, int cntPos, unordered_map<int, vector<int>> &vowelMap, int prevVowel,
                            vector<vector<int>> &dp) {
        if (cntPos >= n)
            return 1;
        if (dp[cntPos][prevVowel] != -1)
            return dp[cntPos][prevVowel];
        vector<int> followingArr = vowelMap[prevVowel];
        int ans = 0;
        for (int vowelInd : followingArr) {
            int tmp = getVowelPermutation(n, cntPos + 1, vowelMap, vowelInd, dp);
            ans = (ans + tmp) % MOD;
        }
        dp[cntPos][prevVowel] = ans;
        return ans;
    }

    int countVowelPermutation(int n) {
        unordered_map<int, vector<int>> vowelMap;
        vector<int> zeroPos = {1, 2, 3, 4, 5};
        vector<int> onePos = {2};
        vector<int> twoPos = {1, 3};
        vector<int> threePos = {1, 2, 4, 5};
        vector<int> fourPos = {3, 5};
        vector<int> fivePos = {1};
        vowelMap[0] = zeroPos;
        vowelMap[1] = onePos;
        vowelMap[2] = twoPos;
        vowelMap[3] = threePos;
        vowelMap[4] = fourPos;
        vowelMap[5] = fivePos;
        vector<vector<int>> dp(n + 1, vector<int>(7, -1));
        return getVowelPermutation(n, 0, vowelMap, 0, dp);
    }
};