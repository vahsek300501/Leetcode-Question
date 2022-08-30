class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix.at(0).size();
//      Transposing the matrix
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<m;j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
//      swapping each row
        for(int i=0;i<n;i++) {
            int j = 0;
            int k = m-1;
            while(j<k) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = tmp;
                j++;
                k--;
            }
        }
    }
};