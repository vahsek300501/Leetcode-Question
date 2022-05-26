class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<int>> visited;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            visited.push_back(tmp);
        }

        queue<pair<int, int>> traversalQueue;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    visited[i].push_back(0);
                    traversalQueue.push(make_pair(i, j));
                } else {
                    visited[i].push_back(-1);
                }
            }
        }

        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};

        while (!traversalQueue.empty()) {
            pair<int, int> top = traversalQueue.front();
            traversalQueue.pop();
            int cntVal = visited[top.first][top.second];

            for (int i = 0; i < 4; i++) {
                int newX = top.first + xPos[i];
                int newY = top.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                    continue;
                if (visited[newX][newY] == -1 && grid[newX][newY] == 0) {
                    visited[newX][newY] = cntVal + 1;
                    traversalQueue.push(make_pair(newX, newY));
                }
            }
        }

        int maxDistance = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] > maxDistance && grid[i][j] == 0)
                    maxDistance = visited[i][j];
            }
        }
        maxDistance = maxDistance == INT_MIN ? -1 : maxDistance;
        return maxDistance;
    }
};