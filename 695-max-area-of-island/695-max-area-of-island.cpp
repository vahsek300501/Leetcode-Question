class Solution {
public:
    int
    maxAreaOfIslandUtil(vector<vector<int>> &grid, vector<vector<bool>> &visited, int cntX, int cntY, int n, int m) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return 0;
        if (visited[cntX][cntY])
            return 0;
        if (grid[cntX][cntY] == 0)
            return 0;
        visited[cntX][cntY] = true;
        int area = 1;
        area += maxAreaOfIslandUtil(grid, visited, cntX + 1, cntY, n, m);
        area += maxAreaOfIslandUtil(grid, visited, cntX - 1, cntY, n, m);
        area += maxAreaOfIslandUtil(grid, visited, cntX, cntY + 1, n, m);
        area += maxAreaOfIslandUtil(grid, visited, cntX, cntY - 1, n, m);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int tmpArea = maxAreaOfIslandUtil(grid, visited, i, j, n, m);
                    maxi = max(maxi, tmpArea);
                }
            }
        }
        return maxi;
    }
};