class Solution {
public:
    bool isPossibleMinTime(vector<int> &time, long long int totalTrips, long long int cntTime) {
        long long int cntTrips = 0;
        for (int i : time) {
            // if (i > cntTime)
            //     break;
            cntTrips += floor(cntTime / i);
        }

        if (cntTrips >= totalTrips)
            return true;
        return false;
    }

    long long minimumTime(vector<int> &time, int totalTrips) {
        // sort(time.begin(), time.end());
        long long int low = 1;
        long long int high = 100000000000000;
        long long int ans = LONG_LONG_MAX;
        while (low <= high) {
            long long int mid = low + ((high - low) / 2);
            bool isPossible = isPossibleMinTime(time, totalTrips, mid);
            if (isPossible) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};