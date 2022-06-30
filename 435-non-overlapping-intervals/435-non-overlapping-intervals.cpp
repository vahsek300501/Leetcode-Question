class Solution {
public:
    static bool compareIntervals(vector<int> &first, vector<int> &second) {
        return first[1] < second[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = (int) intervals.size();
        sort(intervals.begin(), intervals.end(), compareIntervals);
        int countRemoval = 0;
        int cntEndingTime = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < cntEndingTime) {
                countRemoval++;
                cntEndingTime = min(cntEndingTime, intervals[i][1]);
            } else {
                cntEndingTime = intervals[i][1];
            }
        }
        return countRemoval;
    }
};