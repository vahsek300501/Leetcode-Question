class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if ((int) nums.size() == 0)
            return 0;
        unordered_map<int, bool> freqMap;
        vector<int> tmpArr;
        for (int num : nums) {
            if (freqMap.find(num) != freqMap.end()) {
                continue;
            } else {
                tmpArr.push_back(num);
                freqMap[num] = true;
            }
        }
        sort(tmpArr.begin(), tmpArr.end());
        int maxLen = 1;
        int n = (int) tmpArr.size();
        int tmpLen = 1;
        for (int i = 1; i < n; i++) {
            if (tmpArr[i] - tmpArr[i - 1] == 1) {
                tmpLen++;
                maxLen = max(maxLen, tmpLen);
            } else {
                tmpLen = 1;
            }
        }
        return maxLen;
    }
};