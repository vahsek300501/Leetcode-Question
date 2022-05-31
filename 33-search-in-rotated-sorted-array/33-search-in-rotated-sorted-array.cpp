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

    int findTargetIndex(vector<int> &nums, int startIndex, int endIndex, int target) {
        int start = startIndex;
        int end = endIndex;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target) {
        int pivotIndex = findPivotIndex(nums);
        if(pivotIndex == -1)
            return findTargetIndex(nums,0,(int)nums.size()-1,target);
        int pivotIndexPrev = pivotIndex - 1;
        int targetIndex = -1;
        if (target >= nums[0]) {
            targetIndex = findTargetIndex(nums, 0, pivotIndexPrev, target);
        } else {
            targetIndex = findTargetIndex(nums, pivotIndex, (int) nums.size() - 1, target);
        }
        return targetIndex;
    }
};