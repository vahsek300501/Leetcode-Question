class Solution {
public:
    static int robDynamicProgramming(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
//          Exclusion
            int exclusion = dp[i - 1];
//          Inclusion
            int inclusion = nums[i];
            if (i - 2 >= 0) {
                inclusion += dp[i - 2];
            }
            dp[i] = max(inclusion, exclusion);
        }
        return dp[nums.size() - 1];

    }
    
    int rob2(vector<int> &nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.reserve(nums.size() - 1);
        arr2.reserve(nums.size() - 1);
        for (int i = 0; i < nums.size() - 1; i++) {
            arr1.push_back(nums[i]);
        }
        for (int i = 1; i < nums.size(); i++) {
            arr2.push_back(nums[i]);
        }
        return max(robDynamicProgramming(arr1), robDynamicProgramming(arr2));
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums.at(0);
        return rob2(nums);  
    }
};