class Solution {
public:
    void dfsCountSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int cntX, int cntY, int n, int m,
                            bool &foundIsland) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return;
        if (grid1[cntX][cntY] == 0 && grid2[cntX][cntY] == 0)
            return;
        if (grid1[cntX][cntY] == -1 && grid2[cntX][cntY] == -1)
            return;
        if (grid1[cntX][cntY] == 1 && grid2[cntX][cntY] == 0)
            return;
        if (grid1[cntX][cntY] == 0 && grid2[cntX][cntY] == 1) {
            foundIsland = false;
            return;
        }
        grid1[cntX][cntY] = -1;
        grid2[cntX][cntY] = -1;
        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newX = cntX + xPos[i];
            int newY = cntY + yPos[i];
            dfsCountSubIslands(grid1, grid2, newX, newY, n, m, foundIsland);
        }
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        int n = (int) grid1.size();
        int m = (int) grid1.at(0).size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid1[i][j] == 1 && grid2[i][j] == 1) {
                    bool foundIsland = true;
                    dfsCountSubIslands(grid1, grid2, i, j, n, m, foundIsland);
                    if (foundIsland)
                        count++;
                }
            }
        }
        return count;
    }
};