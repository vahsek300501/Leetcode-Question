class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int prevSum = INT_MAX;
        int prevDiff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int firstNum = nums[i];
            int first = i + 1;
            int last = (int) nums.size() - 1;
            while (first < last) {
                int secondNum = nums[first];
                int thirdNum = nums[last];
                int sum = firstNum + secondNum + thirdNum;
                if (sum == target)
                    return target;
                else if (sum < target) {
                    if (abs(sum - target) < prevDiff) {
                        prevDiff = abs(sum - target);
                        prevSum = sum;
                    }
                    first++;
                } else {
                    if (abs(sum - target) < prevDiff) {
                        prevDiff = abs(sum - target);
                        prevSum = sum;
                    }
                    last--;
                }
            }
        }
        return prevSum;
    }
};