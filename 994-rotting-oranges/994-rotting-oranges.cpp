class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        queue<pair<int, int>> currentOranges;
        int n = grid.size();
        int m = grid.at(0).size();
        int totalFreshOranges = 0;
        int totalOranges = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid.at(i).at(j) == 1) {
                    totalFreshOranges++;
                    totalOranges++;
                }
                if (grid.at(i).at(j) == 2) {
                    currentOranges.push(make_pair(i, j));
                    totalOranges++;
                }
            }
        }
        currentOranges.push(make_pair(-1, -1));
        int cntTime = 0;
        while (true) {
            pair<int, int> tmp = currentOranges.front();
            currentOranges.pop();
            if (currentOranges.empty() && tmp.first == -1) {
                break;
            }
            if (tmp.first == -1) {
                cntTime++;
                currentOranges.push(tmp);
                continue;
            }
            int cntX = tmp.first;
            int cntY = tmp.second;

            if (cntX - 1 >= 0) {
                if (grid.at(cntX - 1).at(cntY) == 1) {
                    currentOranges.push(make_pair(cntX - 1, cntY));
                    grid.at(cntX - 1).at(cntY) = 2;
                    totalFreshOranges--;
                }
            }
            if (cntX + 1 < n) {
                if (grid.at(cntX + 1).at(cntY) == 1) {
                    currentOranges.push(make_pair(cntX + 1, cntY));
                    grid.at(cntX + 1).at(cntY) = 2;
                    totalFreshOranges--;
                }
            }
            if (cntY - 1 >= 0) {
                if (grid.at(cntX).at(cntY - 1) == 1) {
                    currentOranges.push(make_pair(cntX, cntY - 1));
                    grid.at(cntX).at(cntY - 1) = 2;
                    totalFreshOranges--;
                }
            }
            if (cntY + 1 < m) {
                if (grid.at(cntX).at(cntY + 1) == 1) {
                    currentOranges.push(make_pair(cntX, cntY + 1));
                    grid.at(cntX).at(cntY + 1) = 2;
                    totalFreshOranges--;
                }
            }
        }

        if (totalFreshOranges != 0)
            return -1;
        return cntTime;
    }
};