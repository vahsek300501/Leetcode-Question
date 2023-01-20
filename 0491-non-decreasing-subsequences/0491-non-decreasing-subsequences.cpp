class Solution {
public:
    void
    findSubsequenceUtil(vector<int> &nums, int cntIndex, set<vector<int>> &finalAnsSet, vector<int> &cntAns, int n) {
        if (cntIndex >= n)
            return;
        if (cntAns.size() > 1) {
            finalAnsSet.insert(cntAns);
        }
        for (int i = cntIndex + 1; i < n; i++) {
            if (nums.at(i) >= cntAns.at(cntAns.size() - 1)) {
                cntAns.push_back(nums.at(i));
                findSubsequenceUtil(nums, i, finalAnsSet, cntAns, n);
                cntAns.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        set<vector<int>> finalAnsSet;
        vector<vector<int>> finalAns;
        vector<int> cntAns;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            cntAns.push_back(nums.at(i));
            findSubsequenceUtil(nums, i, finalAnsSet, cntAns, n);
            cntAns.pop_back();
        }
        auto itr = finalAnsSet.begin();
        while (itr != finalAnsSet.end()) {
            finalAns.push_back(*itr);
            itr++;
        }
        return finalAns;
    }
};