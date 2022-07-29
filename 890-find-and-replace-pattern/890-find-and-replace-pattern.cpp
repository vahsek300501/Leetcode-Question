class Solution {
public:
    bool isPatternFound(string &pattern, string &word) {
        unordered_map<char, char> wordMap;
        unordered_map<char, char> patternMap;
        int n = (int) pattern.length();
        for (int i = 0; i < n; i++) {
            char wordChar = word[i];
            char patternChar = pattern[i];
            if (wordMap.find(wordChar) != wordMap.end() && patternMap.find(patternChar) != patternMap.end()) {
                if (wordMap[wordChar] == patternChar && patternMap[patternChar] == wordChar)
                    continue;
                else
                    return false;
            }
            if (wordMap.find(wordChar) != wordMap.end() && patternMap.find(patternChar) == patternMap.end())
                return false;
            if (wordMap.find(wordChar) == wordMap.end() && patternMap.find(patternChar) != patternMap.end())
                return false;
            wordMap[wordChar] = patternChar;
            patternMap[patternChar] = wordChar;
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> ans;
        for (string &tmpWord : words) {
            if (isPatternFound(tmpWord, pattern))
                ans.push_back(tmpWord);
        }
        return ans;
    }
};