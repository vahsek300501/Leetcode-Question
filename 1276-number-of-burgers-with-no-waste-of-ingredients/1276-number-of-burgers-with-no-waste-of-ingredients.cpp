class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        int a = tomatoSlices;
        int b = cheeseSlices;
        if (((4 * b) - a) % 2 != 0)
            return ans;
        int y = int(((4 * b) - a) / 2);
        if(y < 0)
            return ans;
        if (b - y < 0)
            return ans;
        ans.push_back(b - y);
        ans.push_back(y);
        return ans;
    }
};