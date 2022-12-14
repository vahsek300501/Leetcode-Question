class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix.at(0).size();
        for(int i = 1;i<n;i++) {
            for(int j = 0;j<m;j++) {
                int minElement = matrix[i][j]+matrix[i-1][j];
                if(j-1 >= 0) {
                    minElement = min(minElement,matrix[i][j]+matrix[i-1][j-1]);
                }
                if(j+1 < m) {
                    minElement = min(minElement,matrix[i][j]+matrix[i-1][j+1]);
                }
                matrix[i][j] = minElement;
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<m;i++) {
            ans = min(ans,matrix[n-1][i]);
        }
        return ans;
    }
};