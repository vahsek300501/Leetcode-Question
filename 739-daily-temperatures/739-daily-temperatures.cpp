class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> ans(temperatures.size());
        stack<pair<int, int>> nextGreater;
        for (int i = (int) temperatures.size() - 1; i >= 0; i--) {
            if (nextGreater.empty()) {
                ans.at(i) = 0;
                nextGreater.push(make_pair(temperatures.at(i), i));
                continue;
            }
            while (true) {
                if (nextGreater.empty()) {
                    ans.at(i) = 0;
                    nextGreater.push(make_pair(temperatures.at(i), i));
                    break;
                } else if (nextGreater.top().first > temperatures.at(i)) {
                    ans.at(i) = nextGreater.top().second - i;
                    nextGreater.push(make_pair(temperatures.at(i), i));
                    break;
                } else {
                    nextGreater.pop();
                }
            }
        }
        return ans;
    }
};