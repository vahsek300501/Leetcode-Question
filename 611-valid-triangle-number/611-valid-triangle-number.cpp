class Solution {
public:
    int getTriangularNumberIndex(vector<int> &nums, int first, int last, int sum) {
        int start = first;
        int end = last;
        int ans = -1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (nums[mid] < sum) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int triangleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int countNums = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int first = nums[i];
                int second = nums[j];
                int thirdIndex = getTriangularNumberIndex(nums, j + 1, (int) nums.size() - 1, first + second);
                if (thirdIndex != -1) {
                    countNums += (thirdIndex - j);
                }
            }
        }
        return countNums;
    }
};