class Solution {
public:
    int numDecodingRecursive(string s, int cntIndex) {
        if (cntIndex > s.length())
            return 0;
        if (cntIndex == s.length())
            return 1;
        if (s.at(cntIndex) == '0')
            return 0;
        if (cntIndex == s.length() - 1)
            return 1;

        int singleCharacter = numDecodingRecursive(s, cntIndex + 1);
        int doubleNumber = ((int(s.at(cntIndex)) - 48) * 10) + ((int(s.at(cntIndex + 1)) - 48));
        int doubleCharacters = 0;
        if (doubleNumber <= 26) {
            doubleCharacters = numDecodingRecursive(s, cntIndex + 2);
        }
        return singleCharacter + doubleCharacters;
    }

    int numDecodingMemoization(string s, int cntIndex, int *dp) {
        if (cntIndex > s.length())
            return 0;
        if (cntIndex == s.length())
            return 1;
        if (s.at(cntIndex) == '0')
            return 0;
        if (cntIndex == s.length() - 1)
            return 1;
        if (dp[cntIndex] != -1)
            return dp[cntIndex];
        int singleCharacter = numDecodingRecursive(s, cntIndex + 1);
        int doubleNumber = ((int(s.at(cntIndex)) - 48) * 10) + ((int(s.at(cntIndex + 1)) - 48));
        int doubleCharacters = 0;
        if (doubleNumber <= 26) {
            doubleCharacters = numDecodingRecursive(s, cntIndex + 2);
        }
        dp[cntIndex] = singleCharacter + doubleCharacters;
        return singleCharacter + doubleCharacters;
    }

    int numDecodingDynamicProgramming(string s) {
        int dp[s.length() + 1];
        for (int i = 0; i <= s.length(); i++) {
            dp[i] = -1;
        }
        dp[s.length()] = 1;
        
        if(s.at(s.length()-1) != '0')
            dp[s.length() - 1] = 1;
        else
            dp[s.length() - 1] = 0;
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s.at(i) == '0') {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i + 1];
            int doubleNumber = ((int(s.at(i)) - 48) * 10) + ((int(s.at(i + 1)) - 48));
            if (doubleNumber <= 26) {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }

    int numDecodings(string s) {
        return numDecodingDynamicProgramming(s);
    }
};