class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> ans(n, -1);
        ans[n - 1] = -1;
        stack<int> nextGreater;
        nextGreater.push(nums[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            int cntElement = nums[i];
            while (!nextGreater.empty() && nextGreater.top() <= cntElement) {
                nextGreater.pop();
            }
            if (nextGreater.empty()) {
                nextGreater.push(cntElement);
                continue;
            } else {
                ans[i] = nextGreater.top();
                nextGreater.push(cntElement);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int cntElement = nums[i];
            while (!nextGreater.empty() && nextGreater.top() <= cntElement) {
                nextGreater.pop();
            }
            if (nextGreater.empty()) {
                nextGreater.push(cntElement);
                continue;
            } else {
                ans[i] = nextGreater.top();
                nextGreater.push(cntElement);
            }
        }

        return ans;
    }
};