#define MOD 1000000007
class Solution {
public:
    int findSecondThirdSumStart(vector<long long int> &prefixSum, int start, int end, long long int firstSum) {
        int n = (int) prefixSum.size();
        int firstSumStartInd = start - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            long long int secondSum = prefixSum[mid] - firstSum;
            long long int thirdSum = prefixSum[n - 1] - prefixSum[mid];
            if (firstSum > secondSum) {
                start = mid + 1;
            } else if (firstSum <= secondSum && thirdSum < secondSum) {
                end = mid - 1;
            } else {
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }

    int findSecondThirdSumEnd(vector<long long int> &prefixSum, int start, int end, long long int firstSum) {
        int n = (int) prefixSum.size();
        int firstSumStartInd = start - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            long long int secondSum = prefixSum[mid] - firstSum;
            long long int thirdSum = prefixSum[n - 1] - prefixSum[mid];
            if (firstSum > secondSum) {
                start = mid + 1;
            } else if (firstSum <= secondSum && thirdSum < secondSum) {
                end = mid - 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }


    int waysToSplit(vector<int> &nums) {
        int n = (int) nums.size();
        vector<long long int> prefixSum(n, -1);
        int ans = 0;
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            long long int firstSum = prefixSum[i];
            int start = findSecondThirdSumStart(prefixSum, i + 1, n - 2, firstSum);
            if (start == -1)
                continue;
            int end = findSecondThirdSumEnd(prefixSum, i + 1, n - 2, firstSum);
            int tmp = (start - end + 1)%MOD;
            ans = ((ans % MOD) + (tmp % MOD)) % MOD;
        }
        return ans;
    }
};