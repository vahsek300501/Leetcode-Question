class Solution {
public:
    vector<char> rotateRow(vector<char> &cntRow) {
        int n = (int) cntRow.size();
        vector<char> rotatedRow(n, '.');
        int cntBlock = n;
        for (int i = n - 1; i >= 0; i--) {
            if (cntRow[i] == '*') {
                rotatedRow[i] = '*';
                cntBlock = i;
                continue;
            }
            if (cntRow[i] == '#') {
                rotatedRow[cntBlock - 1] = '#';
                cntRow[i] = '.';
                cntBlock = cntBlock - 1;
            }
        }
        return rotatedRow;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        int n = (int) box.size();
        int m = (int) box.at(0).size();
        vector<vector<char>> tmpRotatedMatrix;
        for (int i = 0; i < n; i++) {
            vector<char> tmp = rotateRow(box.at(i));
            tmpRotatedMatrix.push_back(tmp);
        }
        vector<vector<char>> ans;
        for (int i = 0; i < m; i++) {
            vector<char> cntRow;
            for (int j = n - 1; j >= 0; j--) {
                cntRow.push_back(tmpRotatedMatrix[j][i]);
            }
            ans.push_back(cntRow);
        }
        return ans;
    }
};