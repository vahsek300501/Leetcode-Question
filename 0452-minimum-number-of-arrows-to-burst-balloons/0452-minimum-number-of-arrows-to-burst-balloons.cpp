class Solution {
public:
    static bool comparePoints(vector<int> &e1, vector<int> &e2) {
        return e1[0] < e2[0];
    }

    int findMinArrowShots(vector<vector<int>> &points) {
        int n = (int) points.size();
        sort(points.begin(), points.end());
        int arrowCount = 1;
        int cntArrowPosition = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] <= cntArrowPosition) {
                cntArrowPosition = min(cntArrowPosition, points[i][1]);
            } else {
                arrowCount++;
                cntArrowPosition = points[i][1];
            }
        }
        return arrowCount;
    }
};