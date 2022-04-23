class Solution {
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        vector<int> ans;
        ans.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(-1);
        }
        int cntInd = 0;
        for (int num : nums) {
            if (num < pivot) {
                ans.at(cntInd) = num;
                cntInd++;
            }
        }
        for (int num : nums) {
            if (num == pivot) {
                ans.at(cntInd) = num;
                cntInd++;
            }
        }
        for (int num : nums) {
            if (num > pivot) {
                ans.at(cntInd) = num;
                cntInd++;
            }
        }
        return ans;
    }
};