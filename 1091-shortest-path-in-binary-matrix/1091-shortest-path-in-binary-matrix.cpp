class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        vector<int> xPos = {1, -1, 0, 0, 1, 1, -1, -1};
        vector<int> yPos = {0, 0, 1, -1, 1, -1, 1, -1};
        vector<vector<bool>> visited;
        for (int i = 0; i < grid.size(); i++) {
            vector<bool> tmp;
            visited.push_back(tmp);
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                visited[i].push_back(false);
            }
        }
        queue<pair<int, pair<int, int>>> traversalQueue;
        traversalQueue.push(make_pair(1, make_pair(0, 0)));
        int minCount = INT_MAX;
        int n = (int) grid.size();
        visited[0][0] = true;

        while (!traversalQueue.empty()) {
            pair<int, pair<int, int>> top = traversalQueue.front();
            int cntX = top.second.first;
            int cntY = top.second.second;
            traversalQueue.pop();

            if (grid[cntX][cntY] == 1)
                continue;
            if (cntX == n - 1 && cntY == n - 1)
                minCount = min(minCount, top.first);

            for (int i = 0; i < 8; i++) {
                if (cntX + xPos[i] < 0 || cntY + yPos[i] < 0 || cntX + xPos[i] >= n || cntY + yPos[i] >= n)
                    continue;
                if (!visited[cntX + xPos[i]][cntY + yPos[i]]) {
                    traversalQueue.push(make_pair(top.first + 1, make_pair(cntX + xPos[i], cntY + yPos[i])));
                    visited[cntX + xPos[i]][cntY + yPos[i]] = true;
                }
            }
        }
        if (minCount == INT_MAX)
            return -1;
        return minCount;
    }
};