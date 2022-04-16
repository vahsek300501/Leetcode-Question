class Solution {
public:
    vector<int> getMaxFromLeft(vector<int> &heights) {
        vector<int> maxHeight(heights.size(), -1);
        int cntMaxHeight = heights.at(0);
        int maxHeightIndex = 0;
        for (int i = 1; i < heights.size(); i++) {
            if (cntMaxHeight < heights.at(i)) {
                maxHeight.at(i) = -1;
                cntMaxHeight = heights.at(i);
                maxHeightIndex = i;
            } else {
                maxHeight.at(i) = maxHeightIndex;
            }
        }
        return maxHeight;
    }

    vector<int> getMaxFromRight(vector<int> &heights) {
        vector<int> maxHeight(heights.size(), -1);
        int cntMaxHeight = heights.at(heights.size() - 1);
        int maxHeightIndex = (int) heights.size() - 1;
        for (int i = (int) heights.size() - 2; i >= 0; i--) {
            if (cntMaxHeight < heights.at(i)) {
                maxHeight.at(i) = -1;
                cntMaxHeight = heights.at(i);
                maxHeightIndex = i;
            } else {
                maxHeight.at(i) = maxHeightIndex;
            }
        }
        return maxHeight;
    }


    int trap(vector<int> &height) {
        vector<int> maxHeightLeft = getMaxFromLeft(height);
        vector<int> maxHeightRight = getMaxFromRight(height);
        int maxWaterTrapped = 0;
        for (int i = 0; i < height.size(); i++) {
            if (maxHeightLeft.at(i) == -1 || maxHeightRight.at(i) == -1)
                continue;
            int tmp = min(height.at(maxHeightLeft.at(i)), height.at(maxHeightRight.at(i)));
            maxWaterTrapped += tmp - height.at(i);
        }
        return maxWaterTrapped;
    }
};