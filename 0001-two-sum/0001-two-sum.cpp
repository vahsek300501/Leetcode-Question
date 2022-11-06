class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> umap;
        int first=0,second=0;
        for(int i=0;i<nums.size();i++) {
            int req = target - nums.at(i);
            if(umap.find(req) != umap.end()){
                first = i;
                second = umap[req];
                break;
            }
            umap[nums.at(i)] = i;
        }
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(second);
        return ans;
        
    }
};