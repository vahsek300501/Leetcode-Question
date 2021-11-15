class Solution {
public:
    static vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp;
        dp.push_back(vector<int>{nums.at(0)});

        for (int i = 1; i < nums.size(); i++) {
            int ind = -1;
            int maxSize = INT_MIN;
            for (int j = i - 1; j >= 0; j--) {
                int a = nums.at(i) % nums.at(j);
                int tmpSize = dp.at(j).size();
                bool found = tmpSize > maxSize;
                if (found && (a == 0)) {
                    maxSize = int(dp.at(j).size());
                    ind = j;
                }
            }
            if (maxSize == INT_MIN && ind == -1) {
                dp.push_back(vector<int>{nums.at(i)});
                continue;
            } else {
                vector<int> tmpVec(dp.at(ind).begin(), dp.at(ind).end());
                tmpVec.push_back(nums.at(i));
                dp.push_back(tmpVec);
            }
        }

        int maxLenAns = INT_MIN;
        int maxLenInd = -1;

        for (int i = 0; i < dp.size(); i++) {
            int tmpSize = dp.at(i).size();

            if (tmpSize > maxLenAns) {
                maxLenAns = int(dp.at(i).size());
                maxLenInd = i;
            }
        }
        return dp.at(maxLenInd);
    }
};