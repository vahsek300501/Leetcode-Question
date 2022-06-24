class Solution {
public:
    void markIsland(vector<vector<int>> &grid, vector<vector<int>> &visited, int cntX, int cntY, int n, int m,
                    queue<pair<int, pair<int, int>>> &queue) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return;
        if (visited[cntX][cntY] != -1)
            return;
        if (grid[cntX][cntY] == 0)
            return;
        visited[cntX][cntY] = 0;
        grid[cntX][cntY] = -1;
        queue.push(make_pair(0, make_pair(cntX, cntY)));
        markIsland(grid, visited, cntX + 1, cntY, n, m, queue);
        markIsland(grid, visited, cntX - 1, cntY, n, m, queue);
        markIsland(grid, visited, cntX, cntY + 1, n, m, queue);
        markIsland(grid, visited, cntX, cntY - 1, n, m, queue);
    }
    int shortestBridge(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<int>> distance(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> traversalQueue;

        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    markIsland(grid, distance, i, j, n, m, traversalQueue);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};

        int mini = INT_MAX;
        while (!traversalQueue.empty()) {
            pair<int, pair<int, int>> top = traversalQueue.front();
            traversalQueue.pop();
            if (grid[top.second.first][top.second.second] == 1) {
                mini = min(mini, top.first);
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int newX = top.second.first + xPos[i];
                int newY = top.second.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                    continue;
                if (distance[newX][newY] != -1)
                    continue;
                if (grid[newX][newY] == -1)
                    continue;
                traversalQueue.push(make_pair(top.first + 1, make_pair(newX, newY)));
                distance[newX][newY] = top.first + 1;
            }
        }
        return mini - 1;
    }
};