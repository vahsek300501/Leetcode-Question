class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> charFreqStr1(26, 0);
        vector<int> charFreqStr2(26, 0);
        for (char ch: word1) {
            charFreqStr1[ch - 'a'] += 1;
        }
        for (char ch: word2) {
            charFreqStr2[ch - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++) {
            if (charFreqStr1[i] == charFreqStr2[i])
                continue;
            if(charFreqStr1[i] == 0 && charFreqStr2[i] != 0)
                return false;
            if(charFreqStr1[i] != 0 && charFreqStr2[i] == 0)
                return false;
            bool found = false;
            for (int j = i + 1; j < 26; j++) {
                if (charFreqStr1[j] == charFreqStr2[i] && charFreqStr1[j] != 0) {
                    int tmp = charFreqStr1[i];
                    charFreqStr1[i] = charFreqStr1[j];
                    charFreqStr1[j] = tmp;
//                    swap(charFreqStr1[j], charFreqStr1[i]);
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
};