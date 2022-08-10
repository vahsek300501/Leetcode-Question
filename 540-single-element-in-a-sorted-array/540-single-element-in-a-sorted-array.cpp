class Solution {
public:
    int isSingleElement(vector<int> & nums,int s,int e) {
        if(e>=s) {
            int mid = s+((e-s)/2);
            if(mid == 0) {
                if(nums[mid] != nums[mid+1]){
                    return mid;
                }
            }
            else if(mid == nums.size()-1) {
                if(nums[mid] != nums[mid-1]){
                    return mid;
                }
            }
            else {
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                    return mid;
                }
            }

            int a = isSingleElement(nums,s,mid-1);
            int b = isSingleElement(nums,mid+1,e);
            if(a!=-1 && b==-1){
                return a;
            }
            else if(a == -1 && b !=-1) {
                return b;
            }
            else {
                return -1;
            }
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums.at(0);
        int ind = isSingleElement(nums,0,nums.size()-1);
        return nums.at(ind);
    }
};