class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};