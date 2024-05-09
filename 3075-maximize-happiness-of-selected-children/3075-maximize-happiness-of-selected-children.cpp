class Solution {
public:
    long long maximumHappinessSum(vector<int> &happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long int ans = 0;
        int childPickedCount = 0;
        for (int i = (int) happiness.size() - 1; i >= 0 && k > 0; i--, k--) {
            long long int cntChildVal = max(0, happiness[i] - childPickedCount);
            childPickedCount++;
            if (cntChildVal <= 0)
                break;
            ans += cntChildVal;
        }
        return ans;
    }
};