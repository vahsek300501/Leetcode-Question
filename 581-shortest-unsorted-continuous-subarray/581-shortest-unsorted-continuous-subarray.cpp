class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp;
        for(int i=0;i<nums.size();i++) {
            tmp.push_back(nums.at(i));
        }
        sort(tmp.begin(),tmp.end());
        int start = -1;
        int end = -1;
        for(int i = 0;i<nums.size();i++) {
            if(nums.at(i) != tmp.at(i)) {
                if(start == -1)
                    start = i;
                else
                    end = i;
            }
        }
        if(start == -1)
            return 0;
        return end-start+1;
    }
};