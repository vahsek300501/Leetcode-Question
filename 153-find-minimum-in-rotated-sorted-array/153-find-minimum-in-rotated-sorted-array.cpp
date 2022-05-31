class Solution {
public:
    int findPivotIndex(vector<int> &nums) {
        int start = 0;
        int end = (int) nums.size() - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (nums[mid] < nums[0]) {
                if (ans == -1)
                    ans = mid;
                else {
                    if (mid < ans)
                        ans = mid;
                }
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    int findMin(vector<int> &nums) {
        int pivotIndex = findPivotIndex(nums);
        if (pivotIndex == -1)
            return nums[0];
        return nums[pivotIndex];
    }
};