class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int *nextGreaterElementArray = new int[nums2.size()];
        for (int i = 0; i < nums2.size(); i++) {
            nextGreaterElementArray[i] = -1;
        }
        stack<int> nextGreaterStack;
        for (int i = (int) nums2.size() - 1; i >= 0; i--) {
            if (nextGreaterStack.empty()) {
                nextGreaterElementArray[i] = -1;
                nextGreaterStack.push(nums2.at(i));
            } else {
                while (true) {
                    if (nextGreaterStack.empty()) {
                        nextGreaterElementArray[i] = -1;
                        nextGreaterStack.push(nums2.at(i));
                        break;
                    } else if (nextGreaterStack.top() > nums2.at(i)) {
                        nextGreaterElementArray[i] = nextGreaterStack.top();
                        nextGreaterStack.push(nums2.at(i));
                        break;
                    } else {
                        nextGreaterStack.pop();
                    }
                }
            }
        }

        vector<int> ans;
        for (int i : nums1) {
            for (int j = 0; j < nums2.size(); j++) {
                if (i == nums2[j]) {
                    ans.push_back(nextGreaterElementArray[j]);
                }
            }
        }
        return ans;
    }
};