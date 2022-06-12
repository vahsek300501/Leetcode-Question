class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int first = 0;
        int last = 0;
        unordered_map<int, int> freqMap;
        int maxi = INT_MIN;
        int cntSum = 0;
        while (first < nums.size() && last < nums.size()) {
            int cntNum = nums.at(last);
            if (freqMap.find(cntNum) == freqMap.end()) {
                freqMap[cntNum] = 1;
                cntSum += cntNum;
                maxi = max(maxi, cntSum);
                last++;
            } else {
                while (true) {
                    if (nums[first] == cntNum) {
                        cntSum = cntSum - nums[first];
                        freqMap.erase(nums[first]);
                        first++;
                        break;
                    }
                    cntSum = cntSum - nums[first];
                    freqMap.erase(nums[first]);
                    first++;
                }
            }
        }
        return maxi;
    }

};