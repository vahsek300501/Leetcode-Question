#define MOD 1000000007
class Solution {
public:
    int
    numFactorsBinaryTreeRecursion(vector<int> &arr, int cntNum, unordered_map<int, int> &countMap) {
        if (countMap[cntNum] != -1)
            return countMap[cntNum];
        int ans = 1;
        for (int val : arr) {
            if (cntNum % val == 0 && countMap.find(cntNum / val) != countMap.end()) {
                int first = numFactorsBinaryTreeRecursion(arr, val, countMap);
                int second = numFactorsBinaryTreeRecursion(arr, cntNum / val, countMap);
                long long int tmp = (((long long int)first % MOD) * ((long long int)second % MOD)) % MOD;
                ans = ((tmp % MOD) + (ans % MOD)) % MOD;
            }
        }
        countMap[cntNum] = ans;
        return ans;
    }

    int numFactoredBinaryTrees(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n = (int) arr.size();
        unordered_map<int, int> countMap;
        for (int i = 0; i < n; i++) {
            countMap[arr[i]] = -1;
        }
        int finalAns = 0;
        for (int val:arr) {
            int tmp = numFactorsBinaryTreeRecursion(arr, val, countMap);
            finalAns = ((finalAns % MOD) + (tmp % MOD)) % MOD;
        }
        return finalAns;
    }
};