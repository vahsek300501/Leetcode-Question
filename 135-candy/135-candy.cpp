class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = (int) ratings.size();
        vector<int> leftCandyDistribution(n, 1);
        vector<int> rightCandyDistribution(n, 1);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                leftCandyDistribution[i] = leftCandyDistribution[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                rightCandyDistribution[i] = rightCandyDistribution[i + 1] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            ans += max(leftCandyDistribution[i], rightCandyDistribution[i]);
        }
        return ans;
    }
};