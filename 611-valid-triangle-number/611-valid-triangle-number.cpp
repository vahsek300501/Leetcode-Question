class Solution {
public:
    bool validNumber(int firstEdge, int secondEdge, int thirdEdge) {
        if (firstEdge + secondEdge > thirdEdge && secondEdge + thirdEdge > firstEdge &&
            thirdEdge + firstEdge > secondEdge && abs(firstEdge - secondEdge) < thirdEdge &&
            abs(secondEdge - thirdEdge) < firstEdge && abs(thirdEdge - firstEdge) < secondEdge)
            return true;
        return false;
    }

    int getTriangularNumberCount(vector<int> &nums, int start, int end, int firstEdge, int secondEdge) {
        int ans = 0;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            bool validNumbersFound = validNumber(firstEdge, secondEdge, nums[mid]);
            if (validNumbersFound) {
                ans += mid - start + 1;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int triangleNumber(vector<int> &nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int triangularNumberCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int firstEdge = nums[i];
                int secondEdge = nums[j];
                triangularNumberCount += getTriangularNumberCount(nums, j + 1, n - 1, firstEdge, secondEdge);
            }
        }
        return triangularNumberCount;
    }
};