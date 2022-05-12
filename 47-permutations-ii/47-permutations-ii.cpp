class Solution {
public:
    bool nextPermutation(vector<int> &nums) {
        bool foundInd = false;
        int ind = -1;
        for (int i = (int) nums.size() - 2; i >= 0; i--) {
            if (nums.at(i) < nums.at(i + 1)) {
                foundInd = true;
                ind = i;
                break;
            }
        }
        if (!foundInd) {
            sort(nums.begin(), nums.end());
            return false;
        }
        int nextGreaterInd = -1;
        int nextGreaterElement = INT_MAX;
        for (int i = ind + 1; i < nums.size(); i++) {
            if (nums.at(i) > nums.at(ind) && nums.at(i) < nextGreaterElement) {
                nextGreaterElement = nums.at(i);
                nextGreaterInd = i;
            }
        }
        swap(nums.at(ind), nums.at(nextGreaterInd));
        vector<int> tmpVec;
        for (int i = ind + 1; i < nums.size(); i++) {
            tmpVec.push_back(nums.at(i));
        }
        sort(tmpVec.begin(), tmpVec.end());
        int i = ind + 1;
        for (int sortedNum : tmpVec) {
            nums.at(i) = sortedNum;
            i++;
        }
        return true;
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        while (true) {
            bool found = nextPermutation(nums);
            ans.push_back(nums);
            if (!found)
                break;
        }
        return ans;
    }
};