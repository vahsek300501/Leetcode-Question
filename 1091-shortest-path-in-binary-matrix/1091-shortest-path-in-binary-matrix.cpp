class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<vector<int>> distance(n, vector<int>(m, -1));
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        queue<pair<int, pair<int, int>>> traversalQueue;
        traversalQueue.push(make_pair(1, make_pair(0, 0)));

        vector<int> xPos = {1, -1, 0, 0, 1, 1, -1, -1};
        vector<int> yPos = {0, 0, 1, -1, 1, -1, 1, -1};

        distance[0][0] = 1;
        while (!traversalQueue.empty()) {
            pair<int, pair<int, int>> top = traversalQueue.front();
            traversalQueue.pop();
            if (top.second.first == n - 1 && top.second.second == m - 1)
                return top.first;

            for (int i = 0; i < 8; i++) {
                int newX = top.second.first + xPos[i];
                int newY = top.second.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                    continue;
                if (grid[newX][newY] == 1)
                    continue;
                if (distance[newX][newY] != -1)
                    continue;
                traversalQueue.push(make_pair(top.first + 1, make_pair(newX, newY)));
                distance[newX][newY] = top.first + 1;
            }
        }
        return distance[n - 1][m - 1];
    }
};