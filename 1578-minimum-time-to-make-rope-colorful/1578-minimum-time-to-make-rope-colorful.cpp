class Solution {
public:
    int minCost(string colors, vector<int> &neededTime) {
        int n = (int) neededTime.size();
        if (n == 1)
            return 0;
        int prev = 0;
        int cnt = 1;
        int minCost = 0;

        while (cnt < n && prev < n) {
            if (colors[prev] != colors[cnt]) {
                prev = cnt;
                cnt++;
                continue;
            }
            if (neededTime[prev] <= neededTime[cnt]) {
                minCost += neededTime[prev];
                prev = cnt;
                cnt++;
            } else {
                minCost += neededTime[cnt];
                cnt++;
            }
        }
        return minCost;
    }
};