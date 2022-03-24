class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int maxSum = INT_MIN;
        int cntSum = 0;
        int maxNum = INT_MIN;
        for (int num : nums) {
            if(num > maxNum)
                maxNum = num;
            if (cntSum + num < 0) {
                cntSum = 0;
                continue;
            } else {
                cntSum += num;
            }
            if (cntSum > maxSum)
                maxSum = cntSum;
        }
        if(maxSum == INT_MIN)
            return maxNum;
        return maxSum;
    }
};