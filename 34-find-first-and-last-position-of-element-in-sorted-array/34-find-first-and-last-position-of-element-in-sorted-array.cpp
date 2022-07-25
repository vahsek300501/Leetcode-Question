class Solution {
public:
    int getLowerBound(vector<int> &nums, int target) {
        int start = 0;
        int last = (int) nums.size() - 1;
        int ans = -1;
        while (start <= last) {
            int mid = start + ((last - start) / 2);
            if (nums[mid] == target) {
                ans = mid;
                last = mid - 1;
            } else if (nums[mid] > target) {
                last = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    int getUpperBound(vector<int> &nums, int target) {
        int start = 0;
        int last = (int) nums.size() - 1;
        int ans = -1;
        while (start <= last) {
            int mid = start + ((last - start) / 2);
            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            } else if (nums[mid] > target) {
                last = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans;
        ans.push_back(getLowerBound(nums, target));
        ans.push_back(getUpperBound(nums, target));
        return ans;
    }
};