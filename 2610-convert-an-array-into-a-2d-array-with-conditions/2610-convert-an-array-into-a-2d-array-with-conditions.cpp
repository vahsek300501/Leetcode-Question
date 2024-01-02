class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> freqMap;
        for (int num: nums) {
            if (freqMap.find(num) != freqMap.end())
                freqMap[num] += 1;
            else
                freqMap[num] = 1;
        }
        int maxCount = -1;
        auto itr = freqMap.begin();
        while (itr != freqMap.end()) {
            maxCount = max(maxCount, itr->second);
            itr++;
        }
        for (int i = 0; i < maxCount; i++) {
            vector<int> tmp;
            ans.push_back(tmp);
        }
        itr = freqMap.begin();
        while (itr != freqMap.end()) {
            for (int i = 0; i < itr->second; i++) {
                ans.at(i).push_back(itr->first);
            }
            itr++;
        }
        return ans;
    }
};