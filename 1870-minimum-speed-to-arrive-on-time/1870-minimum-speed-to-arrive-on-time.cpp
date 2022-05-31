class Solution {
public:
    bool isPossibleSpeed(vector<int> &dist, long long int speed, double hour) {
        double totalTime = 0;
        int n = (int) dist.size();
        for (int i = 0; i < n - 1; i++) {
            double tmp = ceil(((double) dist[i]) / ((double) speed));
            totalTime += tmp;
        }
        totalTime += (((double) dist[n - 1]) / ((double) speed));

        if (totalTime <= hour)
            return true;
        return false;
    }

    int minSpeedOnTime(vector<int> &dist, double hour) {
        long long int start = 1;
        long long int end = 10000000;
        long long int ans = -1;
        while (start <= end) {
            long long int mid = start + ((end - start) / 2);
            bool isPossible = isPossibleSpeed(dist, mid, hour);
            if (isPossible) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }

        }
        return ans;
    }
};