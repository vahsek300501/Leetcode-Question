class Solution {
public:
    int countArrangementsUtil(int n, vector<bool> &visited, int cntIndex) {
        if (cntIndex > n) {
            return 1;
        }

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i])
                continue;
            if (i % cntIndex == 0 || cntIndex % i == 0) {
                visited[i] = true;
                count = count + countArrangementsUtil(n, visited, cntIndex + 1);
                visited[i] = false;
            }
        }
        return count;
    }

    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        return countArrangementsUtil(n, visited, 1);
    }
};