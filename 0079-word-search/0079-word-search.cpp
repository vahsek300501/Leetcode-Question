class Solution {
public:
    bool existUtil(vector<vector<char>> &board, vector<vector<bool>> &visited, string &word, int cntIndex, int cntX,
                   int cntY, int n, int m) {
        if (cntIndex >= word.length())
            return true;
        if (cntX < 0 || cntY < 0 || cntX >= n || cntY >= m)
            return false;
        if (board[cntX][cntY] != word.at(cntIndex))
            return false;
        if (visited[cntX][cntY])
            return false;
        visited[cntX][cntY] = true;
        bool top = existUtil(board, visited, word, cntIndex + 1, cntX + 1, cntY, n, m);
        bool bottom = existUtil(board, visited, word, cntIndex + 1, cntX - 1, cntY, n, m);
        bool left = existUtil(board, visited, word, cntIndex + 1, cntX, cntY + 1, n, m);
        bool right = existUtil(board, visited, word, cntIndex + 1, cntX, cntY - 1, n, m);
        visited[cntX][cntY] = false;
        return top || bottom || left || right;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int n = (int) board.size();
        int m = (int) board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word.at(0)) {
                    bool found = existUtil(board, visited, word, 0, i, j, n, m);
                    if (found)
                        return true;
                }
            }
        }
        return false;
    }
};