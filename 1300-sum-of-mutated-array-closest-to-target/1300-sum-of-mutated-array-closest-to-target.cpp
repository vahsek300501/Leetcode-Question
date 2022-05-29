class Solution {
public:
    long long int changedSum(vector<int> &arr, long long int midVal) {
        long long int sum = 0;
        for (int i : arr) {
            if (i < midVal) {
                sum += i;
            } else {
                sum += midVal;
            }
        }
        return sum;
    }

    int getMax(vector<int> &arr) {
        int maxVal = INT_MIN;
        for (int i:arr) {
            if (i > maxVal)
                maxVal = i;
        }
        return maxVal;
    }

    int findBestValue(vector<int> &arr, int target) {
        long long int start = 0;
        long long int end = getMax(arr);
        long long int n = (int) arr.size();
        long long int ans = INT_MAX;
        long long int prevSum = INT_MAX;

        while (start <= end) {
            long long int mid = start + ((end - start) / 2);
            long long int sum = changedSum(arr, mid);

            if (abs(target - sum) < abs(target - prevSum)) {
                ans = mid;
                prevSum = sum;
            } else if (abs(target - sum) == abs(target - prevSum) && mid < ans) {
                ans = mid;
            }

            if (sum < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return (int) ans;
    }
};