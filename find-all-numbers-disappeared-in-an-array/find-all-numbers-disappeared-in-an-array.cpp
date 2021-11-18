class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++) {
            if(umap.find(nums.at(i)) != umap.end()) {
                umap[nums.at(i)] += 1;
            } else {
                umap[nums.at(i)] = 1;
            }
        }
        int i = 1;
        while(i<=nums.size()) {
            if(umap.find(i) == umap.end())
                ans.push_back(i);
            i++;
        }
        return ans;
    }
};