class Solution {
public:
    bool isMaxValuePossible(long long int n, long long int maxValue, long long int maxSum, long long int index) {
        long long int lastInd = n - 1;
        long long int sum = maxValue;
        if (index > 0) {
            long long int leftIndexToOne = ((1 - (maxValue - 1)) / -1) + 1;
            if (leftIndexToOne > index) {
                long long int a = ((2 * (maxValue - 1)) + ((index - 1) * (-1))) * index;
                long long int tmpSum = a / 2;
                sum += tmpSum;
            } else {
                long long int remainingInd = index - leftIndexToOne;
                long long int a = (maxValue * leftIndexToOne);
                long long int tmpSumToOne = a / 2;
                sum += tmpSumToOne;
                sum += remainingInd;
            }
        }
        if (lastInd - index > 0) {
            long long int rightIndexToOne = ((1 - (maxValue - 1)) / -1) + 1;
            if (rightIndexToOne > lastInd - index) {
                long long int a = ((2 * (maxValue - 1)) + ((lastInd - index - 1) * (-1))) * (lastInd - index);
                long long int tmpSum = a/2;
                sum += tmpSum;
            } else {
                long long int remainingInd = lastInd - index - rightIndexToOne;
                long long int a = (maxValue * rightIndexToOne);
                long long int tmpSumToOne = a / 2;
                sum += tmpSumToOne;
                sum += remainingInd;
            }
        }

        if (sum <= maxSum)
            return true;
        return false;
    }

    int maxValue(int n, int index, int maxSum) {
        long long int low = 1;
        long long int high = maxSum;
        long long int ans = INT_MIN;
        while (low <= high) {
            long long int mid = low + ((high - low) / 2);
            bool found = isMaxValuePossible(n, mid, maxSum, index);
            if (found) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int) ans;
    }
};