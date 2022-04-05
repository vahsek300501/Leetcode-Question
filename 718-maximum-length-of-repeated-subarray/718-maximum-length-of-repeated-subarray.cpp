class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int **dp = new int *[nums1.size() + 1];
        for (int i = 0; i <= nums1.size(); i++) {
            dp[i] = new int[nums2.size() + 1];
        }
        for (int i = 0; i <= nums1.size(); i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= nums2.size(); i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1.at(i - 1) == nums2.at(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i <= nums1.size(); i++) {
            for (int j = 0; j <= nums2.size(); j++) {
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};