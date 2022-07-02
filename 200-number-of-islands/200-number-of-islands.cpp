class Solution {
public:
    void numIslandUtil(vector<vector<char>> &grid, vector<vector<bool>> &visited, int n, int m, int cntX, int cntY) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return;
        if(visited[cntX][cntY])
            return;
        if (grid[cntX][cntY] == '0')
            return;
        visited[cntX][cntY] = true;
        numIslandUtil(grid, visited, n, m, cntX + 1, cntY);
        numIslandUtil(grid, visited, n, m, cntX - 1, cntY);
        numIslandUtil(grid, visited, n, m, cntX, cntY + 1);
        numIslandUtil(grid, visited, n, m, cntX, cntY - 1);
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    numIslandUtil(grid, visited, n, m, i, j);
                }
            }
        }
        return count;
    }
};