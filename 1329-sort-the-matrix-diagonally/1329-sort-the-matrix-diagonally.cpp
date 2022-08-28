class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int n = (int) mat.size(); // rows
        int m = (int) mat[0].size(); // columns
        for (int i = n - 1; i >= 0; i--) {
            vector<int> tmpDiagonal;
            int x = i;
            int y = 0;
            int newX = i;
            int newY = 0;

            while (x < n && y < m) {
                tmpDiagonal.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tmpDiagonal.begin(), tmpDiagonal.end());
            int j = 0;
            while (newX < n && newY < m && j < (int) tmpDiagonal.size()) {
                mat[newX][newY] = tmpDiagonal[j];
                newX++;
                newY++;
                j++;
            }
        }
        for (int i = 1; i < m; i++) {
            vector<int> tmpDiagonal;
            int x = 0;
            int y = i;
            int newX = 0;
            int newY = i;
            while (x < n && y < m) {
                tmpDiagonal.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tmpDiagonal.begin(), tmpDiagonal.end());
            int j = 0;
            while (newX < n && newY < m && j < (int) tmpDiagonal.size()) {
                mat[newX][newY] = tmpDiagonal[j];
                newX++;
                newY++;
                j++;
            }
        }
        return mat;
    }
};