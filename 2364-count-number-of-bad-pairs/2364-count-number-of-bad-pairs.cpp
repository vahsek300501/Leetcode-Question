class Solution {
public:
    long long countBadPairs(vector<int> &nums) {
        long long int n = (long long int) nums.size();
        vector<long long int> newNums;
        newNums.reserve(n);
        for (int i = 0; i < n; i++) {
            newNums.push_back((long long int)(nums[i] - i));
        }
        long long int totalPairs = (n * (n - 1)) / 2;
        long long int goodPairs = 0;
        unordered_map<long long int, long long int> similarNums;
        for (int i = n - 1; i >= 0; i--) {
            int cntNum = newNums[i];
            if (similarNums.find(cntNum) == similarNums.end()) {
                similarNums[cntNum] = (long long int)1;
            } else {
                similarNums[cntNum] += (long long int)1;
            }
        }
        auto itr = similarNums.begin();
        while (itr != similarNums.end()) {
            long long int tmp = ((itr->second) * (itr->second - 1)) / 2;
            goodPairs += tmp;
            itr++;
        }
        return totalPairs - goodPairs;
    }
};