class Solution {
public:
    int longestPalindrome(vector<string> &words) {
        unordered_map<string, int> freqMap;
        for (string &tmp: words) {
            if (freqMap.find(tmp) != freqMap.end())
                freqMap[tmp] += 1;
            else
                freqMap[tmp] = 1;
        }

        int palindromeLengthCount = 0;
        bool isSingleWordTaken = false;
        for (string word: words) {
            string revWord = word;
            reverse(revWord.begin(), revWord.end());
            if (word == revWord && freqMap[word] % 2 == 0) {
                palindromeLengthCount += (freqMap[word] * 2);
                freqMap[word] = 0;
                continue;
            }
            if (word == revWord && freqMap[word] % 2 != 0) {
                palindromeLengthCount += ((freqMap[word] - 1) * 2);
                freqMap[word] = 1;
                if (!isSingleWordTaken) {
                    palindromeLengthCount += 2;
                    isSingleWordTaken = true;
                    freqMap[word] = 0;
                }

                continue;
            }
            if (freqMap[word] == 0)
                continue;
            if (freqMap.find(revWord) != freqMap.end()) {
                if (freqMap[revWord] == 0)
                    continue;
                else {
                    palindromeLengthCount += 4;
                    freqMap[revWord]--;
                    freqMap[word]--;
                }
            }
        }
        return palindromeLengthCount;
    }

};