class Solution {
public:
    void combinationSumUtil(vector<int> &candidates, int cntSum, int target, int cntIndex, vector<int> cntArr,
                            vector<vector<int>> &ans) {
        if (cntSum > target)
            return;
        if (cntIndex >= candidates.size())
            return;
        if (cntSum == target) {
            ans.push_back(cntArr);
            return;
        }
        cntArr.push_back(candidates.at(cntIndex));
        combinationSumUtil(candidates, cntSum + candidates.at(cntIndex), target, cntIndex, cntArr, ans);
        cntArr.pop_back();
        combinationSumUtil(candidates, cntSum, target, cntIndex + 1, cntArr, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmpArr;
        combinationSumUtil(candidates, 0, target, 0, tmpArr, ans);
        return ans;
    }
};