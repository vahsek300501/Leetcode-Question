class Solution {
public:
    vector<int> getNextSmallest(vector<int> &heights) {
        stack<pair<int, int>> nextSmallestStack;
        vector<int> ans;
        ans.reserve(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            ans.push_back(-1);
        }
        int n = (int) heights.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!nextSmallestStack.empty() && nextSmallestStack.top().first >= heights.at(i)) {
                nextSmallestStack.pop();
            }

            if (nextSmallestStack.empty()) {
                ans.at(i) = n - i - 1;
                nextSmallestStack.push(make_pair(heights.at(i), i));
            } else {
                ans.at(i) = nextSmallestStack.top().second - i - 1;
                nextSmallestStack.push(make_pair(heights.at(i), i));
            }
        }
        return ans;
    }

    vector<int> getPrevSmallest(vector<int> &heights) {
        stack<pair<int, int>> prevSmallestStack;
        vector<int> ans;
        ans.reserve(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            ans.push_back(-1);
        }
        int n = (int) heights.size();
        for (int i = 0; i < n; i++) {
            while (!prevSmallestStack.empty() && prevSmallestStack.top().first >= heights.at(i)) {
                prevSmallestStack.pop();
            }
            if (prevSmallestStack.empty()) {
                ans.at(i) = i;
                prevSmallestStack.push(make_pair(heights.at(i), i));
            } else {
                ans.at(i) = i - prevSmallestStack.top().second - 1;
                prevSmallestStack.push(make_pair(heights.at(i), i));
            }
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights) {
        vector<int> nextSmallest = getNextSmallest(heights);
        vector<int> prevSmallest = getPrevSmallest(heights);
        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            if ((nextSmallest.at(i) + prevSmallest.at(i) + 1) * heights.at(i) > maxArea)
                maxArea = (nextSmallest.at(i) + prevSmallest.at(i) + 1) * heights.at(i);
        }
        return maxArea;
    }
};