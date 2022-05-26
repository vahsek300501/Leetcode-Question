class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<pair<int, int>> traversalQueue;
        bool isAllZero = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 0;
                    traversalQueue.push(make_pair(i, j));
                }
                if(grid[i][j] != 0)
                    isAllZero = false;
            }
        }

        if(isAllZero)
            return 0;
        

        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};

        while (!traversalQueue.empty()) {
            pair<int, int> top = traversalQueue.front();
            traversalQueue.pop();
            int nextTime = visited[top.first][top.second] + 1;
            for (int i = 0; i < 4; i++) {
                int newX = top.first + xPos[i];
                int newY = top.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                    continue;
                if (grid[newX][newY] == 1 && visited[newX][newY] == -1) {
                    grid[newX][newY] = 2;
                    visited[newX][newY] = nextTime;
                    traversalQueue.push(make_pair(newX, newY));
                }
            }
        }

        int minTime = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
                if (visited[i][j] == -1)
                    continue;
                minTime = max(minTime, visited[i][j]);
            }
        }
        return minTime;
    }
};