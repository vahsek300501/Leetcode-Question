class Solution {
public:
    void generateMatrixLayerWise(vector<vector<int>> &ans, int &count, int startX, int startY, int xNegativeLim,
                                 int xPositiveLim, int yNegativeLim, int yPositiveLim) {
        int cntX = startX;
        int cntY = startY;
        char cntDir = 'R';

        while (true) {
            if (cntX == startX && cntY == startY && cntDir == 'U')
                break;
            if (cntDir == 'R') {
                if (cntY < yPositiveLim) {
                    ans[cntX][cntY] = count;
                    count++;
                    cntY++;
                } else {
                    cntDir = 'D';
                    cntX++;
                    cntY--;
                }
            } else if (cntDir == 'D') {
                if (cntX < xPositiveLim) {
                    ans[cntX][cntY] = count;
                    count++;
                    cntX++;
                } else {
                    cntDir = 'L';
                    cntY--;
                    cntX--;
                }
            } else if (cntDir == 'L') {
                if (cntY >= yNegativeLim) {
                    ans[cntX][cntY] = count;
                    count++;
                    cntY--;
                } else {
                    cntDir = 'U';
                    cntX--;
                    cntY++;
                }
            } else {
                if (cntX >= xNegativeLim) {
                    ans[cntX][cntY] = count;
                    count++;
                    cntX--;
                } else {
                    cntX++;
                    break;
                }
            }
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            ans.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans.at(i).push_back(-1);
            }
        }

        int startX = 0;
        int startY = 0;
        int count = 1;
        int xNegativeLim = 0;
        int xPositiveLim = n;
        int yNegativeLim = 0;
        int yPositiveLim = n;

        int layers = int(n / 2)+1;
        for (int i = 0; i < layers; i++) {
            generateMatrixLayerWise(ans, count, startX, startY, xNegativeLim, xPositiveLim, yNegativeLim, yPositiveLim);
            startX++;
            startY++;
            xNegativeLim++;
            xPositiveLim--;
            yNegativeLim++;
            yPositiveLim--;
        }
        return ans;
    }
};