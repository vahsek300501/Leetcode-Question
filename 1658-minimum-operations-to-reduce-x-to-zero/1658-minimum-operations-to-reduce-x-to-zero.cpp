class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        long long int tmpSum = 0;
        for (int i:nums) tmpSum += i;
        if(tmpSum == x)
            return nums.size();
        long long int requiredSum = tmpSum - x;
        long long int sum = 0;
        int first = 0;
        int second = 0;
        int maxLen = 0;

        while (first < nums.size() && second < nums.size()) {
            if (sum + nums[second] < requiredSum) {
                sum += nums[second];
                second++;
            } else if (sum + nums[second] > requiredSum) {
                sum = sum - nums[first];
                first++;
            } else if (sum + nums[second] == requiredSum) {
                sum = sum+nums[second];
                maxLen = max(maxLen, second - first + 1);
                second++;
            }
        }
        if (maxLen == 0)
            return -1;
        return (int) nums.size() - maxLen;
    }
};