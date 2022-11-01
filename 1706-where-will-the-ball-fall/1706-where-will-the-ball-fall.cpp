class Solution {
public:
    int getBallFallPosition(vector<vector<int>> &grid, int startX, int startY) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        int cntX = startX;
        int cntY = startY;
        int ballFallY = -1;
        while (true) {
            if (cntX >= n) {
                ballFallY = cntY;
                break;
            }
            if (cntY < 0 || cntY >= m)
                break;
            if (cntY == 0 && grid[cntX][cntY] == -1)
                break;
            if (cntY == m - 1 && grid[cntX][cntY] == 1)
                break;
            if (grid[cntX][cntY] == 1 && grid[cntX][cntY + 1] != 1)
                break;
            if (grid[cntX][cntY] == -1 && grid[cntX][cntY - 1] != -1)
                break;
            if (grid[cntX][cntY] == 1 && grid[cntX][cntY + 1] == 1) {
                cntX++;
                cntY++;
                continue;
            }
            if (grid[cntX][cntY] == -1 && grid[cntX][cntY - 1] == -1) {
                cntX++;
                cntY--;
                continue;
            }
        }
        return ballFallY;
    }

    vector<int> findBall(vector<vector<int>> &grid) {
        vector<int> ans;
        int m = (int) grid.at(0).size();
        for (int i = 0; i < m; i++) {
            int ballFallY = getBallFallPosition(grid, 0, i);
            ans.push_back(ballFallY);
        }
        return ans;
    }
};