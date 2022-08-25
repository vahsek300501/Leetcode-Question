class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> firstFreqMap;
        unordered_map<char,int> secondFreqMap;
        for(char ch:ransomNote) {
            if(firstFreqMap.find(ch) != firstFreqMap.end()) {
                firstFreqMap[ch] += 1;
            } else
                firstFreqMap[ch] = 1;
        }
        for(char ch:magazine) {
            if(secondFreqMap.find(ch) != secondFreqMap.end())
                secondFreqMap[ch] += 1;
            else
                secondFreqMap[ch] = 1;
        }
        auto itr = firstFreqMap.begin();
        while(itr != firstFreqMap.end()) {
            char ch = itr->first;
            int freq = itr->second;
            if(secondFreqMap.find(ch) == secondFreqMap.end())
                return false;
            else {
                if(secondFreqMap[ch] < freq)
                    return false;
            }
            itr++;
        }
        return true;
    }
};