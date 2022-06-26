class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = (int) cardPoints.size();
        vector<int> prefixSum;
        vector<int> reversedPrefixSum;
        prefixSum.push_back(cardPoints[0]);
        reversedPrefixSum.push_back(cardPoints[n - 1]);
        for (int i = 1; i < n; i++) {
            prefixSum.push_back(prefixSum[i - 1] + cardPoints[i]);
        }
        int j = 1;
        for (int i = n - 2; i >= 0; i--) {
            reversedPrefixSum.push_back(reversedPrefixSum[j - 1] + cardPoints[i]);
            j++;
        }
        int maxi = INT_MIN;
        for (int i = 0; i <= k; i++) {
            int frontPick = i;
            int backPick = k - i;
            int sum = 0;
            if (frontPick == 0) {
                sum = reversedPrefixSum[k - 1];
            } else if (backPick == 0) {
                sum = prefixSum[k - 1];
            } else {
                sum = prefixSum[frontPick - 1] + reversedPrefixSum[backPick - 1];
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};