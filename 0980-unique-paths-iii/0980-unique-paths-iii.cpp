class Solution {
public:
    int getUniquePathCount(vector<vector<int>> &grid, vector<vector<bool>> &visited, int endX,
                           int endY, int cntWalkable, int &countPaths, int cntX, int cntY, int n, int m) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return 0;
        if (visited[cntX][cntY])
            return 0;
        if (grid[cntX][cntY] == -1)
            return 0;
        if (cntX == endX && cntY == endY) {
            if (cntWalkable == 0) {
                countPaths++;
                return 1;
            }
            return 0;
        }
        visited[cntX][cntY] = true;
        int top = getUniquePathCount(grid, visited, endX, endY, cntWalkable - 1, countPaths, cntX + 1,
                                     cntY, n, m);
        int bottom = getUniquePathCount(grid, visited, endX, endY, cntWalkable - 1, countPaths,
                                        cntX - 1, cntY, n, m);
        int left = getUniquePathCount(grid, visited, endX, endY, cntWalkable - 1, countPaths, cntX,
                                      cntY + 1, n, m);
        int right = getUniquePathCount(grid, visited, endX, endY, cntWalkable - 1, countPaths, cntX,
                                       cntY - 1, n, m);
        visited[cntX][cntY] = false;
        return top + bottom + left + right;
    }

    int uniquePathsIII(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int startX = -1, startY = -1;
        int endX = -1, endY = -1;
        int countWalkable = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] == 2) {
                    endX = i;
                    endY = j;
                }
                if (grid[i][j] == 0) {
                    countWalkable++;
                }
            }
        }
        int countPaths = 0;
        int ans = getUniquePathCount(grid, visited, endX, endY, countWalkable + 1, countPaths, startX,
                                     startY, n, m);
        return countPaths;
    }
};