class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        if (s1 == s2)
            return true;
        unordered_map<char, int> s1FreqMap;
        for (char ch: s1) {
            if (s1FreqMap.find(ch) != s1FreqMap.end())
                s1FreqMap[ch] += 1;
            else
                s1FreqMap[ch] = 1;
        }

        unordered_map<char, int> slidingWindowMap;
        int first = 0;
        int second = 0;
        while (second < s1.length()) {
            if (slidingWindowMap.find(s2[second]) != slidingWindowMap.end())
                slidingWindowMap[s2[second]] += 1;
            else
                slidingWindowMap[s2[second]] = 1;
            second++;
        }
        if (s1FreqMap == slidingWindowMap)
            return true;
        while (second < s2.length()) {
            slidingWindowMap[s2[first]] -= 1;
            if (slidingWindowMap[s2[first]] == 0) {
                slidingWindowMap.erase(s2[first]);
            }
            first++;
            if (slidingWindowMap.find(s2[second]) != slidingWindowMap.end())
                slidingWindowMap[s2[second]] += 1;
            else
                slidingWindowMap[s2[second]] = 1;
            second++;
            if (slidingWindowMap == s1FreqMap)
                return true;
        }
        if (slidingWindowMap == s1FreqMap)
            return true;
        return false;
    }
};