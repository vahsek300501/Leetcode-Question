class Solution {
public:
    bool isCycleFoundDfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int cntX, int cntY, int parentX,
                         int parentY, int n, int m, char prevChar) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return false;
        if (grid[cntX][cntY] != prevChar)
            return false;
        if (visited[cntX][cntY]) {
            return true;
        }
        visited[cntX][cntY] = true;
        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int newX = cntX + xPos[i];
            int newY = cntY + yPos[i];
            if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                continue;
            if (newX == parentX && newY == parentY)
                continue;
            if (grid[newX][newY] != prevChar)
                continue;
            bool foundCycle = isCycleFoundDfs(grid, visited, newX, newY, cntX, cntY, n, m, prevChar);
            if (foundCycle)
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    bool found = isCycleFoundDfs(grid, visited, i, j, -1, -1, n, m, grid[i][j]);
                    if (found)
                        return true;
                }
            }
        }
        return false;
    }
};