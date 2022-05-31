class Solution {
public:
    bool isPossibleToDivide(vector<int> &nums, long long int requiredBalls, long long int maxOperations) {
        long long int reqOperations = 0;
        for (int i:nums) {
            if (i <= requiredBalls)
                continue;
            double tmp = ((double) i) / ((double) requiredBalls);
            reqOperations = reqOperations + ceil(tmp) - 1;
        }
        if (reqOperations <= maxOperations)
            return true;
        return false;
    }

    int minimumSize(vector<int> &nums, int maxOperations) {
        long long int start = 1;
        long long int end = *max_element(nums.begin(), nums.end());
        long long int ans = INT_MAX;
        while (start <= end) {
            long long int mid = start + ((end - start) / 2);
            bool isPossible = isPossibleToDivide(nums, mid, maxOperations);
            if (isPossible) {
                ans = min(ans, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};