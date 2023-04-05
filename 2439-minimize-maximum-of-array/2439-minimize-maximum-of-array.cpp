class Solution {
public:
    bool isPossibleToMinimize(vector<int> &nums, long long int requiredNum) {
        if (nums[0] > requiredNum)
            return false;
        long long int additionElements = 0;
        additionElements = (requiredNum-nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= requiredNum) {
                additionElements += (requiredNum - nums[i]);
                continue;
            } else {
                long long int cntNum = nums[i];
                long long int prevNum = nums[i - 1];
                long long int requiredSubs = abs(requiredNum - cntNum);
                if (requiredSubs > additionElements)
                    return false;
                additionElements = additionElements - requiredSubs;
            }
        }
        return true;
    }

    long long int minimizeArrayValue(vector<int> &nums) {
        long long int minNumber = INT_MAX;
        long long int maxNumber = INT_MIN;
        for (int tmp: nums) {
            if (tmp < minNumber)
                minNumber = tmp;
            if (tmp > maxNumber)
                maxNumber = tmp;

        }

        long long int low = minNumber;
        long long int high = maxNumber;
        long long int ans = maxNumber;
        while (low <= high) {
            long long int mid = low + ((high - low) / 2);
            bool found = isPossibleToMinimize(nums, mid);
            if (found) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};