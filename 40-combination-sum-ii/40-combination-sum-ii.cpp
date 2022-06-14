class Solution {
public:
    void combinationSum2Util(vector<int> &candidates, int cntIndex, int target, vector<vector<int>> &ans,
                             vector<int> &cntArr, int cntSum) {
        if (cntSum == target) {
            ans.push_back(cntArr);
            return;
        }
        if (cntSum > target)
            return;
        if (cntIndex >= candidates.size())
            return;

        for (int i = cntIndex; i < candidates.size(); i++) {
            if (i > cntIndex && candidates[i] == candidates[i - 1])
                continue;
            cntArr.push_back(candidates[i]);
            combinationSum2Util(candidates, i + 1, target, ans, cntArr, cntSum + candidates[i]);
            cntArr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmpAns;
        combinationSum2Util(candidates, 0, target, ans, tmpAns, 0);
        return ans;
    }
};