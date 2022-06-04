class Solution {
public:
    bool isPossibleToPlaceQueen(vector<vector<bool>> &visited, int cntX, int cntY, int n) {
        // Horizontally upwards Check
        for (int i = cntX - 1; i >= 0; i--) {
            if (visited[i][cntY])
                return false;
        }

        // Left Diagonal Check
        int i = cntX - 1;
        int j = cntY - 1;
        while (i >= 0 && j >= 0) {
            if (visited[i][j])
                return false;
            i--;
            j--;
        }

        // Right Diagonal Check
        i = cntX - 1;
        j = cntY + 1;
        while (i >= 0 && j < n) {
            if (visited[i][j])
                return false;
            i--;
            j++;
        }
        return true;
    }

    vector<vector<string>>ans;

    void nQueens(vector<vector<bool>> &visited, int n, int cntRow) {
        if (cntRow >= n) {
            vector<string> rowArr;
            for (int i = 0; i < n; i++) {
                string tmp;
                for (int j = 0; j < n; j++) {
                    if (visited[i][j]) {
                        tmp += 'Q';
                    } else {
                        tmp += '.';
                    }
                }
                rowArr.push_back(tmp);
            }
            ans.push_back(rowArr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isPossibleToPlaceQueen(visited, cntRow, i, n)) {
                visited[cntRow][i] = true;
                nQueens(visited, n, cntRow + 1);
                visited[cntRow][i] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        nQueens(visited, n, 0);
        return ans;
    }
};