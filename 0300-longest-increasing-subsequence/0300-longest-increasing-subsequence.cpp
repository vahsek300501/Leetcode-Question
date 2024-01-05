class Solution {
public:
    int lengthOfLISBinarySearch(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> cntSequence;
        cntSequence.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            int cntElement = nums[i];
            int index = lower_bound(cntSequence.begin(), cntSequence.end(), cntElement) - cntSequence.begin();
            if (index >= (int) cntSequence.size())
                cntSequence.push_back(cntElement);
            else
                cntSequence[index] = cntElement;
        }
        return (int) cntSequence.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLISBinarySearch(nums);   
    }
};