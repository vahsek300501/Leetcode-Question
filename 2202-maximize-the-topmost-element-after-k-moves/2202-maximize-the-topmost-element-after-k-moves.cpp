class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k == 0)
            return nums.at(0);
        if(nums.size() == 1 && k%2 != 0)
            return -1;
        k--;
        int maxElem = INT_MIN;
        int i = 0;
        while(k!=0 && i < nums.size()) {
            if(nums.at(i) > maxElem)
                maxElem = nums.at(i);
            k--;
            i++;
        }
        if(i+1 < nums.size() && nums.at(i+1) > maxElem)
            maxElem = nums.at(i+1);
        if(maxElem == INT_MIN)
            return -1;
        return maxElem;
    }
};