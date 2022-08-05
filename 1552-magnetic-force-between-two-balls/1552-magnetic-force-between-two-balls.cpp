class Solution {
public:
    bool isPossibleToPutBalls(vector<int> &position, int m, long long int minValue) {
        int n = (int) position.size();
        int countBalls = 0;
        int start = 0;
        for (int i = start + 1; i < n; i++) {
            if (abs(position[start] - position[i]) >= minValue) {
                countBalls++;
                start = i;
            }
        }
        return countBalls >= m-1;
    }

    int maxDistance(vector<int> &position, int m) {
        sort(position.begin(), position.end());
        int n = (int) position.size();
        long long int start = 1;
        long long int end = position[n - 1] - position[0];
        long long int ans = -1;
        while (start <= end) {
            long long int mid = start + ((end - start) / 2);
            bool found = isPossibleToPutBalls(position, m, mid);
            if (found) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};