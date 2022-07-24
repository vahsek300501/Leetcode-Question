class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = (int) matrix.size();
        int m = (int) matrix[0].size();
        for (int i = 0; i < n; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][m - 1]) {
                vector<int> cntArr = matrix[i];
                int tmp = lower_bound(cntArr.begin(), cntArr.end(), target) - cntArr.begin();
                if (tmp >= m)
                    return true;
                if(cntArr[tmp] == target)
                    return true;
            }
        }
        return false;
    }
};