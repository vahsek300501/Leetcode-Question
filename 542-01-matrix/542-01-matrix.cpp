class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = (int) mat.size();
        int m = (int) mat.at(0).size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<pair<int, int>> traversalQueue;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    traversalQueue.push(make_pair(i, j));
                    visited[i][j] = 0;
                }
            }
        }

        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};
        while (!traversalQueue.empty()) {
            pair<int, int> top = traversalQueue.front();
            traversalQueue.pop();
            int nextNodeVal = visited[top.first][top.second] + 1;
            for (int i = 0; i < 4; i++) {
                int newX = top.first + xPos[i];
                int newY = top.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                    continue;
                if (mat[newX][newY] == 1 && visited[newX][newY] == -1) {
                    visited[newX][newY] = nextNodeVal;
                    traversalQueue.push(make_pair(newX, newY));
                }
            }
        }
        return visited;
    }
};