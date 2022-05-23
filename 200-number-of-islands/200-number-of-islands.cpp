class Solution {
public:
    void dfsIslands(vector<vector<char>> &grid, vector<vector<bool>> &visited, int cntX, int cntY, int n, int m) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return;
        if (visited[cntX][cntY])
            return;
        if (grid[cntX][cntY] == '0')
            return;
        visited[cntX][cntY] = true;
        dfsIslands(grid, visited, cntX + 1, cntY, n, m);
        dfsIslands(grid, visited, cntX - 1, cntY, n, m);
        dfsIslands(grid, visited, cntX, cntY + 1, n, m);
        dfsIslands(grid, visited, cntX, cntY - 1, n, m);
    }

    int numIslands(vector<vector<char>> &grid) {
        vector<vector<bool>> visited;
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        for (int i = 0; i < n; i++) {
            vector<bool> tmp;
            visited.push_back(tmp);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i].push_back(false);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfsIslands(grid, visited, i, j, n, m);
                }
            }
        }
        return count;
    }
};