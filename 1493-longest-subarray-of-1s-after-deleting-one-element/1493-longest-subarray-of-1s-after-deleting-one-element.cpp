class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> prefixArr(n, 0);
        vector<int> suffixArr(n, 0);
        if (nums[0] == 1)
            prefixArr[0] = 1;
        if (nums[n - 1] == 1)
            suffixArr[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0)
                prefixArr[i] = 0;
            else
                prefixArr[i] = prefixArr[i - 1] + 1;
        }
        if (prefixArr[n - 1] == n)
            return n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0)
                suffixArr[i] = 0;
            else
                suffixArr[i] = suffixArr[i + 1] + 1;
        }
        int maxi = INT_MIN;
        for (int i : prefixArr) {
            maxi = max(maxi, i);
        }
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == 0) {
                maxi = max(maxi, prefixArr[i-1] + suffixArr[i + 1]);
            }
        }
        return maxi;
    }
};