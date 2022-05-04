class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int first = 0;
        int last = nums.size()-1;
        int count = 0;
        while(first < last) {
            if(nums.at(first) + nums.at(last) == k) {
                count++;
                first++;
                last--;
            } else if(nums.at(first) + nums.at(last) < k)
                first++;
            else
                last--;
        }
        return count;
    }
};