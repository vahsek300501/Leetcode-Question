class Solution {
public:
    bool isPossibleToEat(vector<int> &piles, int h, long long int k) {
        long long int requiredHours = 0;
        for (int pile : piles) {
            auto tmp = (long long int) ceil((double) pile / (double) k);
            requiredHours += tmp;
        }
        return requiredHours <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        sort(piles.begin(), piles.end());
        long long int start = 1;
        long long int end = *max_element(piles.begin(), piles.end());
        long long int ans = -1;
        while (start <= end) {
            long long int mid = start + ((end - start) / 2);
            bool found = isPossibleToEat(piles, h, mid);
            if (found) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return (int)ans;
    }
};