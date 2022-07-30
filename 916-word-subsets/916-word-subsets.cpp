class Solution {
public:
    vector<int> getCombinedWordArray(vector<string> &words) {
        vector<int> letterArray(26, 0);
        for (string &cntWord : words) {
            vector<int> tmpLetterArr(26, 0);
            for (char ch : cntWord) {
                tmpLetterArr[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                letterArray[i] = max(letterArray[i], tmpLetterArr[i]);
            }
        }
        return letterArray;
    }

    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        vector<string> ans;
        vector<int> letterArray = getCombinedWordArray(words2);
        for (string &cntWord : words1) {
            vector<int> tmpLetterArr(26, 0);
            for (char ch : cntWord) {
                tmpLetterArr[ch - 'a']++;
            }
            bool found = true;
            for (int i = 0; i < 26; i++) {
                if (letterArray[i] > 0) {
                    if (tmpLetterArr[i] >= letterArray[i])
                        continue;
                    else {
                        found = false;
                        break;
                    }
                }
            }
            if(found)
                ans.push_back(cntWord);
        }
        return ans;
    }
};