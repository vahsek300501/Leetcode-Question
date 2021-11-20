class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++) {
            if(umap.find(nums.at(i)) != umap.end())
                umap[nums.at(i)] += 1;
            else
                umap[nums.at(i)] = 1;
        }
        for(int i = 0;i<nums.size();i++) {
            if(umap[nums.at(i)] == 1)
                return nums.at(i);
        }
        return -1;
    }
};