class Solution {
public:
    bool isValidDivision(vector<int> &nums, int threshold, int divisor) {
        long long int quotientSum = 0;
        for (int i:nums) {
            double tmpQ = ((double) i / ((double) divisor));
            quotientSum += ceil(tmpQ);
        }
        if (quotientSum <= threshold)
            return true;
        return false;
    }

    int smallestDivisor(vector<int> &nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            bool found = isValidDivision(nums, threshold, mid);
            if (found) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};