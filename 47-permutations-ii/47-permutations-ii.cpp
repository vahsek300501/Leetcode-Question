class Solution {
public:
    void
    permuteUniqueUtil(vector<vector<int>> &ans, vector<int> &cntAns, unordered_map<int, int> &freqMap, int cntIndex,
                      int n) {
        if (cntIndex == n) {
            ans.push_back(cntAns);
            return;
        }

        auto itr = freqMap.begin();
        while (itr != freqMap.end()) {
            if (itr->second != 0) {
                cntAns.push_back(itr->first);
                itr->second = itr->second - 1;
                permuteUniqueUtil(ans, cntAns, freqMap, cntIndex + 1, n);
                cntAns.pop_back();
                itr->second = itr->second + 1;
            }
            itr++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        unordered_map<int, int> freqMap;
        vector<vector<int>> ans;
        vector<int> cntAns;
        for (int num : nums) {
            if (freqMap.find(num) == freqMap.end())
                freqMap[num] = 1;
            else
                freqMap[num] += 1;
        }
        permuteUniqueUtil(ans, cntAns, freqMap, 0, nums.size());
        return ans;
    }
};