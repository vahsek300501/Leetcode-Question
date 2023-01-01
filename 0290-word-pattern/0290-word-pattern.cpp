class Solution {
public:
    static vector<string> getIndividualWords(string &s) {
        istringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }

    bool wordPattern(string &pattern, string &s) {
        unordered_map<char, string> patternStringMapping;
        unordered_map<string, char> stringPatternMapping;
        vector<string> words = getIndividualWords(s);
        if (pattern.length() != words.size())
            return false;
        for (int i = 0; i < pattern.length(); i++) {
            char cntPattern = pattern[i];
            string cntWord = words.at(i);
            if (patternStringMapping.find(cntPattern) != patternStringMapping.end()) {
                if (patternStringMapping[cntPattern] != cntWord)
                    return false;
            }
            if (stringPatternMapping.find(cntWord) != stringPatternMapping.end()) {
                if (stringPatternMapping[cntWord] != cntPattern)
                    return false;
            }
            patternStringMapping[cntPattern] = cntWord;
            stringPatternMapping[cntWord] = cntPattern;
        }
        return true;
    }
};