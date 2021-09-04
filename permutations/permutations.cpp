class Solution {
public:
    unordered_map<int, bool> umap;
    vector<vector<int>> ans;

    void getAllPermutation(vector<int> nums, vector<int>& singlePermutation, int crnt) {
        if(crnt == nums.size()) {
            ans.push_back(singlePermutation);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!umap[nums.at(i)]) {
                singlePermutation.push_back(nums.at(i));
                umap[nums.at(i)] = true;
                getAllPermutation(nums,singlePermutation,crnt+1);
                singlePermutation.pop_back();
                umap[nums.at(i)] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            umap[nums.at(i)] = false;
        }
        vector<int> tmp;
        getAllPermutation(nums,tmp,0);
        return ans;
    }
};