class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        if(nums.size() <= 1)
            return false;
        unordered_map<int, int> umap;
        umap[0] = -1;
        long long int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            int prefixSumRemainder = sum%k;
            if(umap.find(prefixSumRemainder) != umap.end()){
                if(i-umap[prefixSumRemainder] > 1)
                    return true;
            }
                
            else
                umap[prefixSumRemainder] = i;
        }
        return false;
    }
};