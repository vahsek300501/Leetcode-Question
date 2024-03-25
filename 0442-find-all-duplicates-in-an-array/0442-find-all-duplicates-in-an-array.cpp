class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int num: nums) {
            if(umap.find(num) != umap.end())
                umap[num] += 1;
            else
                umap[num] = 1;
        }
        vector<int> ans;
        auto itr = umap.begin();
        while(itr != umap.end()) {
            if(itr->second == 2)
                ans.push_back(itr->first);
            itr++;
        }
        return ans;
    }
};