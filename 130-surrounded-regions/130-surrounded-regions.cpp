class Solution {
public:
    void solve(vector<vector<char>> &board) {
        queue<pair<int, int>> traversalQueue;
        int n = (int) board.size();
        int m = (int) board.at(0).size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                traversalQueue.push(make_pair(i, 0));
            }
            if (board[i][m - 1] == 'O') {
                traversalQueue.push(make_pair(i, m - 1));
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                traversalQueue.push(make_pair(0, i));
            }
            if (board[n - 1][i] == 'O') {
                traversalQueue.push(make_pair(n - 1, i));
            }
        }

        vector<int> xPos = {1, -1, 0, 0};
        vector<int> yPos = {0, 0, 1, -1};

        while (!traversalQueue.empty()) {
            pair<int, int> top = traversalQueue.front();
            traversalQueue.pop();
            board[top.first][top.second] = 'A';
            for (int i = 0; i < 4; i++) {
                int newX = top.first + xPos[i];
                int newY = top.second + yPos[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                    continue;
                if (board[newX][newY] == 'X' || board[newX][newY] == 'A')
                    continue;
                traversalQueue.push(make_pair(newX, newY));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};