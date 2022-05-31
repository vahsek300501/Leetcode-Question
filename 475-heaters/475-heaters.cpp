class Solution {
public:
    long long int getPreviousHeaterDistance(vector<int> &heaters, int houseLocations) {
        int start = 0;
        int end = (int) heaters.size() - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (heaters[mid] == houseLocations) {
                ans = mid;
                break;
            } else if (heaters[mid] < houseLocations) {
                if (ans == -1)
                    ans = mid;
                else if (heaters[mid] > heaters[ans])
                    ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (ans == -1)
            return LONG_LONG_MAX;
        long long int distance = abs(houseLocations - heaters[ans]);
        return distance;
    }

    long long int getNextHeaterDistance(vector<int> &heaters, int houseLocations) {
        int start = 0;
        int end = (int) heaters.size() - 1;
        int ans = INT_MAX;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (heaters[mid] == houseLocations) {
                ans = mid;
                break;
            } else if (heaters[mid] > houseLocations) {
                if (ans == INT_MAX)
                    ans = mid;
                else if (heaters[mid] < heaters[ans])
                    ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (ans == INT_MAX)
            return LONG_LONG_MAX;
        long long int distance = abs(houseLocations - heaters[ans]);
        return distance;
    }

//  Heaters
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<long long int> nearestHeaterDist;
        for (int house : houses) {
            long long int leftDist = getPreviousHeaterDistance(heaters, house);
            long long int rightDist = getNextHeaterDistance(heaters, house);
            nearestHeaterDist.push_back(min(leftDist, rightDist));
        }
        long long int minRadius = LONG_LONG_MIN;
        for (long long int rad : nearestHeaterDist) {
            if (rad > minRadius)
                minRadius = rad;
        }
        return (int) minRadius;
    }
};