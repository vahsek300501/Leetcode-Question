#define MOD 1000000007
class Solution {
public:
    int numFactorBinaryTreeDynamicProgramming(vector<int> &arr) {
        int n = (int) arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<long long int, long long int> countMap;
        for (int i = 0; i < n; i++) {
            countMap[arr[i]] = 1;
        }
        for (int i = 0; i < n; i++) {
            int cntNum = arr[i];
            for (int j = 0; j < i; j++) {
                if (cntNum % arr[j] == 0 && countMap.find(cntNum / arr[j]) != countMap.end()) {
                    long long int first = countMap[arr[j]];
                    long long int second = countMap[cntNum / arr[j]];
                    long long int tmp = (((long long int) first % MOD) * ((long long int) second % MOD)) % MOD;
                    countMap[cntNum] = ((countMap[cntNum] % MOD) + (tmp % MOD)) % MOD;
                }
            }
        }
        long long int ans = 0;
        for (int tmpNode : arr) {
            ans = ((ans % MOD) + (countMap[tmpNode] % MOD)) % MOD;
        }
        return (int) ans;
    }

    int numFactoredBinaryTrees(vector<int> &arr) {
        return numFactorBinaryTreeDynamicProgramming(arr);
    }
};