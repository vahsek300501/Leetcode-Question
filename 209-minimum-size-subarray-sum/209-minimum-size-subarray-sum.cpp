class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int first = 0;
        int last = 0;
        int minLength = INT_MAX;
        long long int sum = 0;
        while (first < nums.size() && last < nums.size()) {
            if (sum >= target) {
                minLength = min(minLength, first - last);
                sum = sum - nums[last];
                last++;
            } else {
                sum += nums[first];
                first++;
            }
        }
        while (sum >= target) {
            minLength = min(minLength, first - last);
            sum = sum - nums[last];
            last++;
        }
        if (minLength == INT_MAX)
            return 0;
        return minLength;
    }
};