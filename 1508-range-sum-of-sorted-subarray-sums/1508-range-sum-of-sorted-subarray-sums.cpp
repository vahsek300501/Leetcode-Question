#define MOD 1000000007
class Solution {
public:
    int rangeSum(vector<int> &nums, int n, int left, int right) {
        vector<int> subarraySum;
        for (int i = 0; i < nums.size(); i++) {
            int tmpSum = 0;
            for (int j = i; j < nums.size(); j++) {
                tmpSum += nums.at(j);
                subarraySum.push_back(tmpSum);
            }
        }
        left = left-1;
        right=right-1;
        // cout<<subarraySum.size()<<endl;
        sort(subarraySum.begin(), subarraySum.end());
        int ansSum = 0;
        for (int i = left; i <= right; i++) {
            int tmpAns = ansSum;
            ansSum = ((subarraySum.at(i) % MOD) + (tmpAns % MOD)) % MOD;
        }
        return ansSum;
    }
};