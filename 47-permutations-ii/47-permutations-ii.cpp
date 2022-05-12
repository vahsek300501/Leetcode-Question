class Solution {
public:
    void permuteUniqueUtil(vector<int> &nums, string cntNum, vector<vector<int>> &ans,
                           unordered_map<string, bool> &isThere, vector<int> &cntAns, vector<bool> &visited) {
        if (cntAns.size() >= nums.size()) {
            if (isThere.find(cntNum) == isThere.end()) {
                ans.push_back(cntAns);
                isThere[cntNum] = true;
            }
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            cntAns.push_back(nums.at(i));
            string tmp = cntNum + to_string(nums.at(i));
            permuteUniqueUtil(nums, tmp, ans, isThere, cntAns, visited);
            visited[i] = false;
            cntAns.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> ans;
        unordered_map<string, bool> isThere;
        vector<int> cntAns;
        permuteUniqueUtil(nums, "", ans, isThere, cntAns, visited);
        return ans;
    }
};