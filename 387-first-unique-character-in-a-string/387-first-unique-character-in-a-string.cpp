class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> freqMap;
        int i = 0;
        for (char ch : s) {
            if (freqMap.find(ch) == freqMap.end()) {
                freqMap[ch] = make_pair(i, 1);
            } else {
                freqMap[ch].second += 1;
            }
            i++;
        }
        int ans = INT_MAX;
        auto itr = freqMap.begin();
        while (itr != freqMap.end()) {
            if (itr->second.second == 1 && itr->second.first < ans) {
                ans = itr->second.first;
            }
            itr++;
        }

        ans = ans == INT_MAX ? -1 : ans;
        return ans;
    }
};