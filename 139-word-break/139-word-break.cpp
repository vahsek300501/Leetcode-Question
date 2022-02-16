class Solution {
public:
    bool wordBreakMemoization(string s, int cntIndex, unordered_map<string, bool> umap, int *dp) {
        if (cntIndex >= s.length())
            return true;
        if (dp[cntIndex] == 1)
            return true;
        if (dp[cntIndex] == 0)
            return false;

        string tmpStr;
        for (int i = cntIndex; i < s.length(); i++) {
            tmpStr += s.at(i);
            if (umap.find(tmpStr) != umap.end()) {
                bool found = wordBreakMemoization(s, i + 1, umap, dp);
                if (found) {
                    dp[cntIndex] = 1;
                    return true;
                }
            }
        }
        dp[cntIndex] = 0;
        return false;
    }

    bool wordBreak(const string &s, vector<string> &wordDict) {
        unordered_map<string, bool> dictionary;
        for (int i = 0; i < wordDict.size(); i++) {
            dictionary[wordDict.at(i)] = true;
        }
        int dp[s.length() + 1];
        for (int i = 0; i <= s.length(); i++)
            dp[i] = -1;
        return wordBreakMemoization(s, 0, dictionary, dp);
    }
};