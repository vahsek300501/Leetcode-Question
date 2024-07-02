class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> nums1FreqMap;
        unordered_map<int, int> nums2FreqMap;
        for (int num: nums1) {
            if (nums1FreqMap.find(num) != nums1FreqMap.end()) {
                nums1FreqMap[num]++;
            } else {
                nums1FreqMap[num] = 1;
            }
        }

        for (int num: nums2) {
            if (nums2FreqMap.find(num) != nums2FreqMap.end()) {
                nums2FreqMap[num]++;
            } else {
                nums2FreqMap[num] = 1;
            }
        }

        vector<int> ans;
        auto itr = nums1FreqMap.begin();
        while (itr != nums1FreqMap.end()) {
            int val = itr->first;
            if (nums2FreqMap.find(val) != nums2FreqMap.end()) {
                int count = min(nums2FreqMap[val], nums1FreqMap[val]);
                for (int i = 0; i < count; i++) {
                    ans.push_back(val);
                }
            }
            itr++;
        }
        return ans;
    }
};