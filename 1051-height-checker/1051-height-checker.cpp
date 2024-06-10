class Solution {
public:
    int heightChecker(vector<int> &heights) {
        vector<int> heightsCopy;
        for (int height: heights) {
            heightsCopy.push_back(height);
        }
        sort(heightsCopy.begin(), heightsCopy.end());
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heightsCopy[i] != heights[i])
                count++;
        }
        return count;
    }
};