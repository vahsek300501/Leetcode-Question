class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = (int) height.size();
        int first = 0;
        int last = n - 1;
        int maxi = INT_MIN;
        while (first < last) {
            int cntWater = (last - first) * min(height[first], height[last]);
            maxi = max(maxi, cntWater);
            if (height[first] <= height[last])
                first++;
            else
                last--;
        }
        return maxi;
    }
};