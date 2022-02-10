class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int maxSum = INT_MIN;
        int cntSum = 0;
        for (int num : nums) {
            if (cntSum + num <= 0) {
                cntSum = 0;
                continue;
            }
            cntSum += num;
            if (cntSum > maxSum)
                maxSum = cntSum;
        }
        if(maxSum == INT_MIN) {
            int maxNumber = INT_MIN;
            for(int i=0;i<nums.size();i++) {
                if(maxNumber < nums.at(i))
                    maxNumber = nums.at(i);
            }
            return maxNumber;
        }
            
        return maxSum;
    }
};