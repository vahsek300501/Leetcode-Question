class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 && n==1)
            return 1;
        int mat[m][n];
        mat[m - 1][n - 1] = 0;
        for (int i = m - 2; i >= 0; i--) {
            mat[i][n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            mat[m - 1][i] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                mat[i][j] = mat[i + 1][j] + mat[i][j + 1];
            }
        }
        return mat[0][0];
    }
};