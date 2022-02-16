class Solution {
public:
    void wordBreak2Helper(const string &s, int cntIndex, string cntSentence, const unordered_map<string, bool> &dictionary, vector<string> &sentences) {
        if (cntIndex >= s.length()) {
            sentences.push_back(cntSentence);
            return;
        }
        string tmpStr;
        for (int i = cntIndex; i < s.length(); i++) {
            tmpStr += s.at(i);
            if (dictionary.find(tmpStr) != dictionary.end()) {
                if (cntIndex == 0) {
                    wordBreak2Helper(s, i + 1, cntSentence + tmpStr, dictionary, sentences);
                } else {
                    string wordToAppend = " ";
                    wordToAppend += tmpStr;
                    wordBreak2Helper(s, i + 1, cntSentence + wordToAppend, dictionary, sentences);
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, bool> dictionary;
        for (auto & i : wordDict) {
            dictionary[i] = true;
        }
        vector<string> sentences;
        wordBreak2Helper(s, 0, "", dictionary, sentences);
        return sentences;
    }
};