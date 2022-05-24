class Solution {
public:
    int
    maxAreaOfIslandUtil(vector<vector<int>> &grid, vector<vector<bool>> &visited, int cntX, int cntY, int n, int m) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return 0;
        if(visited[cntX][cntY])
            return 0;
        if (grid[cntX][cntY] == 0)
            return 0;
        visited[cntX][cntY] = true;
        int up = maxAreaOfIslandUtil(grid, visited, cntX + 1, cntY, n, m);
        int down = maxAreaOfIslandUtil(grid, visited, cntX - 1, cntY, n, m);
        int left = maxAreaOfIslandUtil(grid, visited, cntX, cntY + 1, n, m);
        int right = maxAreaOfIslandUtil(grid, visited, cntX, cntY - 1, n, m);
        return up + left + down + right + 1;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<bool>> visited;
        for (int i = 0; i < n; i++) {
            vector<bool> tmp;
            visited.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i].push_back(false);
            }
        }

        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int tmpArea = maxAreaOfIslandUtil(grid, visited, i, j, n, m);
                    maxArea = max(maxArea, tmpArea);
                }
            }
        }
        if(maxArea == INT_MIN)
            return 0;
        return maxArea;
    }
};