class Solution {
public:
    void
    floodFillUtil(vector<vector<int>> &image, int n, int m, int cntX, int cntY, int color,
                  vector<vector<bool>> &visited,
                  int prevColor) {
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return;
        if (visited[cntX][cntY])
            return;
        if (image[cntX][cntY] != prevColor)
            return;

        visited[cntX][cntY] = true;
        image[cntX][cntY] = color;
        floodFillUtil(image, n, m, cntX + 1, cntY, color, visited, prevColor);
        floodFillUtil(image, n, m, cntX - 1, cntY, color, visited, prevColor);
        floodFillUtil(image, n, m, cntX, cntY + 1, color, visited, prevColor);
        floodFillUtil(image, n, m, cntX, cntY - 1, color, visited, prevColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int n = (int) image.size();
        int m = (int) image.at(0).size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        floodFillUtil(image, n, m, sr, sc, color, visited, image[sr][sc]);
        return image;
    }
};