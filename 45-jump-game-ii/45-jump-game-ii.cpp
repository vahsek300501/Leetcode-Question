class Solution {
public:
    int jump(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> dp(n, -1);
        dp[n - 1] = 0;  // last index need 0 jumps

        for (int i = n - 2; i >= 0; i--) {
            int reqJumps = n - 1 - i;
            if(nums[i] == 0) {
                dp[i] = 10000;
                continue;
            }
                
            if (nums[i] >= reqJumps) {
                dp[i] = 1;
                continue;
            }
            int minJump = 10000;
            for (int j = 1; j <= nums[i]; j++) {
                if (dp[j + i] < minJump)
                    minJump = dp[j + i];
            }
            dp[i] = minJump + 1;
        }
        return dp[0];
    }
};