class Solution {
public:
    int maxCount(vector<int> &banned, int n, int maxSum) {
        unordered_map<int, bool> bannedMap;
        int cntCount = 0;
        long long int cntSum = 0;
        for (int val: banned) {
            bannedMap[val] = true;
        }
        for (int i = 1; i <= n; i++) {
            if (bannedMap.find(i) != bannedMap.end())
                continue;
            if (cntSum + i <= maxSum) {
                cntSum += i;
                cntCount++;
            } else
                break;
        }
        return cntCount;
    }
};