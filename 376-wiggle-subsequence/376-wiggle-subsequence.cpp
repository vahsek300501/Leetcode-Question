class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = (int) nums.size();
        int currDiff = 0;
        int prevDiff = 0;
        int count = 0;
        for (int i = 1; i < n; i++) {
            currDiff = nums[i] - nums[i - 1];
            if(count == 0 && currDiff != 0) {
                prevDiff = currDiff;
                count++;
                continue;
            }
            if ((currDiff > 0 && prevDiff < 0) || (currDiff < 0 && prevDiff >= 0)) {
                prevDiff = currDiff;
                count++;
            }
        }
        return count+1;
    }
};