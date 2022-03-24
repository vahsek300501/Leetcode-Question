class Solution {
public:
    bool wordBreakMemoization(string s, unordered_map<string, bool> &dictionary, int cntIndex, vector<int> &dp) {
        if (cntIndex >= s.length())
            return true;
        if (dp.at(cntIndex) == 1)
            return true;
        if (dp.at(cntIndex) == 0)
            return false;
        string tmpWord;
        for (int i = cntIndex; i < s.length(); i++) {
            tmpWord += s.at(i);
            if (dictionary.find(tmpWord) != dictionary.end()) {
                bool found = wordBreakMemoization(s, dictionary, i + 1, dp);
                if (found) {
                    dp[cntIndex] = 1;
                    return true;
                }
            }
        }
        dp[cntIndex] = 0;
        return false;
    }

    bool wordBreakMemoizationUtil(string s, unordered_map<string, bool> &dictionary) {
        vector<int> dp;
        for (int i = 0; i < s.length(); i++) {
            dp.push_back(-1);
        }
        return wordBreakMemoization(s, dictionary, 0, dp);
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, bool> dict;
        for (auto &i : wordDict) {
            dict[i] = true;
        }
        return wordBreakMemoizationUtil(s, dict);
    }
};