class Solution {
public:
    void dfsEnclaves(vector<vector<int>> &grid, int n, int m, int cntX, int cntY) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return;
        if (grid[cntX][cntY] == -1 || grid[cntX][cntY] == 0)
            return;
        grid[cntX][cntY] = -1;
        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int newX = cntX + xPos[i];
            int newY = cntY + yPos[i];
            dfsEnclaves(grid, n, m, newX, newY);
        }
    }

    int numEnclaves(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        queue<pair<int, int>> traversalQueue;
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfsEnclaves(grid, n, m, i, 0);
            if (grid[i][m - 1] == 1)
                dfsEnclaves(grid, n, m, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1)
                dfsEnclaves(grid, n, m, 0, i);
            if (grid[n - 1][i] == 1)
                dfsEnclaves(grid, n, m, n - 1, i);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};