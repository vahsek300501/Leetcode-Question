class Solution {
public:
    bool isInterleavingMemoization(string &s1, string &s2, string &s3, int str1Ind, int str2Ind, int str3Ind,
                                   vector<vector<int>> &dp) {
        if (str1Ind >= s1.length() && str2Ind >= s2.length())
            return true;
        if (dp[str1Ind][str2Ind] != -1)
            return dp[str1Ind][str2Ind];
        if (str1Ind >= s1.length()) {
            if (s3.at(str3Ind) != s2.at(str2Ind)) {
                dp[str1Ind][str2Ind] = 0;
                return false;
            }
            bool tmp = isInterleavingMemoization(s1, s2, s3, str1Ind, str2Ind + 1, str3Ind + 1, dp);
            if(!tmp)
                dp[str1Ind][str2Ind] = 0;
            else
                dp[str1Ind][str2Ind] = 1;
            return tmp;
        }
        if (str2Ind >= s2.length()) {
            if (s3.at(str3Ind) != s1.at(str1Ind)) {
                dp[str1Ind][str2Ind] = 0;
                return false;
            }
            bool tmp = isInterleavingMemoization(s1, s2, s3, str1Ind + 1, str2Ind, str3Ind + 1, dp);
            if(!tmp)
                dp[str1Ind][str2Ind] = 0;
            else
                dp[str1Ind][str2Ind] = 1;
            return tmp;
        }

        int first = false;
        int second = false;
        if (s1.at(str1Ind) == s3.at(str3Ind)) {
            first = isInterleavingMemoization(s1, s2, s3, str1Ind + 1, str2Ind, str3Ind + 1, dp);
        }
        if (s2.at(str2Ind) == s3.at(str3Ind)) {
            second = isInterleavingMemoization(s1, s2, s3, str1Ind, str2Ind + 1, str3Ind + 1, dp);
        }
        dp[str1Ind][str2Ind] = first || second;
        return first || second;
    }


    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() < s1.length() + s2.length())
            return false;
        if (s3.length() > s1.length() + s2.length())
            return false;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return isInterleavingMemoization(s1, s2, s3, 0, 0, 0, dp);
    }
};