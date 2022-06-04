class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
        int first = 0;
        int second = 0;
        int count = 0;
        int prevCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= left && nums[i] <= right) {
                prevCount = second - first + 1;
                second++;
                count += prevCount;
            } else if (nums[i] < left) {
                count += prevCount;
                second++;
            } else {
                first = i + 1;
                second = i + 1;
                prevCount = 0;
            }
        }
        return count;
    }
};