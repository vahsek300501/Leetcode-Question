class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = (int) mat.size();
        int m = (int) mat.at(0).size();
        queue<pair<int, pair<int, int>>> traversalQueue;
        vector<vector<int>> distance(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    distance[i][j] = 0;
                    traversalQueue.push(make_pair(0, make_pair(i, j)));
                }
            }
        }

        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};

        while (!traversalQueue.empty()) {
            pair<int, pair<int, int>> top = traversalQueue.front();
            traversalQueue.pop();

            for (int i = 0; i < 4; i++) {
                int newX = top.second.first + xPos[i];
                int newY = top.second.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                    continue;
                if (distance[newX][newY] != -1)
                    continue;
                if (mat[newX][newY] == 0)
                    continue;
                distance[newX][newY] = top.first + 1;
                traversalQueue.push(make_pair(top.first + 1, make_pair(newX, newY)));
            }
        }
        return distance;
    }
};