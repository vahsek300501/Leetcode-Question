class Solution {
public:
    int minIncrementForUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, bool> visited;
        visited[nums.at(0)] = true;
        int nextNum = nums.at(0) + 1;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            int cntNum = nums[i];
            if (visited.find(cntNum) != visited.end()) {
                count += (nextNum - nums[i]);
                nums[i] = nextNum;
                visited[nextNum] = true;
                nextNum++;
            } else {
                visited[cntNum] = true;
                nextNum = cntNum + 1;
            }
        }
        return count;
    }
};