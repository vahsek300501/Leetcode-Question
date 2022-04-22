class Solution {
public:
    int characterReplacement(string s, int k) {
        int longestSubstring = INT_MIN;

        unordered_map<char, bool> isPresent;
        for (char &i : s) {
            if (isPresent.find(i) != isPresent.end())
                continue;
            else
                isPresent[i] = true;
        }
        int tmpK = k;
        auto itr = isPresent.begin();
        while (itr != isPresent.end()) {
            char currCh = itr->first;
            int first = 0;
            k = tmpK;
            int last = 0;
            int cntCount = 0;
            while (first < s.length() && last < s.length()) {
                if (s.at(last) == currCh) {
                    cntCount++;
                    last++;
                } else if (s.at(last) != currCh && k > 0) {
                    cntCount++;
                    last++;
                    k--;
                } else {
                    if (longestSubstring < cntCount) {
                        longestSubstring = cntCount;
                    }
                    if (tmpK == 0) {
                        last += 1;
                        first = last;
                        cntCount = 0;
                        continue;
                    }
                    if (s.at(first) == currCh) {
                        first++;
                        cntCount--;
                    } else {
                        first++;
                        k++;
                        cntCount--;
                    }
                }
            }
            if (longestSubstring < cntCount) {
                longestSubstring = cntCount;
            }
            itr++;
        }
        return longestSubstring;
    }
};