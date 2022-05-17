class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int n = (int) image.size();
        int m = (int) image.at(0).size();
        vector<vector<bool>> visited;
        for (int i = 0; i < n; i++) {
            vector<bool> tmp;
            visited.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i].push_back(false);
            }
        }

        queue<pair<int, int>> traversalQueue;
        traversalQueue.push(make_pair(sr, sc));
        visited[sr][sc] = true;
        vector<int> xPos = {0, 0, 1, -1};
        vector<int> yPos = {1, -1, 0, 0};

        while (!traversalQueue.empty()) {
            pair<int, int> top = traversalQueue.front();
            traversalQueue.pop();
            int orgVal = image[top.first][top.second];
            image[top.first][top.second] = newColor;
            for (int i = 0; i < 4; i++) {
                int newX = top.first + xPos[i];
                int newY = top.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                    continue;
                if (visited[newX][newY])
                    continue;
                if (image[newX][newY] != orgVal)
                    continue;
                visited[newX][newY] = true;
                traversalQueue.push(make_pair(newX, newY));
            }
        }
        return image;
    }
};