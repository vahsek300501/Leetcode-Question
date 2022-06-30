class Solution {
public:
    long long int getMinimumMoves(vector<int> &nums,int req) {
        long long int count = 0;
        for(int i : nums) {
            count += abs(req-i);
        }
        return count;
    }
    int minMoves2(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 1)
            return 0;
        sort(nums.begin(),nums.end());
        
        if(n%2 == 0) {
            int a = nums[n/2];
            int b = nums[n/2 - 1];
            return min(getMinimumMoves(nums,a),getMinimumMoves(nums,b));
        }
        int a = nums[n/2];
        return getMinimumMoves(nums,a);
    }
};