class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<long long int> prefixSum(nums.size(),0);
        prefixSum[0] = nums.at(0);
        
        for(int i=1;i<nums.size();i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        long long int ans = -1;
        for(int i = nums.size()-1;i>=2;i--) {
            if(prefixSum[i-1] > nums[i]) {
                ans = prefixSum[i];
                break;
            }
        }
        return ans;
    }
};