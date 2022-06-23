class Solution {
public:
    bool isClosedIsland(vector<vector<int>> &grid, vector<vector<bool>> &visited, int cntX, int cntY, int n, int m) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return false;
        if (visited[cntX][cntY])
            return true;
        if (grid[cntX][cntY] == 1)
            return true;
        visited[cntX][cntY] = true;
        bool top = isClosedIsland(grid, visited, cntX + 1, cntY, n, m);
        bool bottom = isClosedIsland(grid, visited, cntX - 1, cntY, n, m);
        bool left = isClosedIsland(grid, visited, cntX, cntY + 1, n, m);
        bool right = isClosedIsland(grid, visited, cntX, cntY - 1, n, m);
        return top && bottom && left && right;
    }

    int closedIsland(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    bool found = isClosedIsland(grid, visited, i, j, n, m);
                    if (found)
                        count++;
                }
            }
        }
        return count;
    }
};