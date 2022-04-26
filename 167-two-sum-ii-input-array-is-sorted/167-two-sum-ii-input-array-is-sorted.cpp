class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int firstPtr = 0;
        int lastPtr = (int) numbers.size() - 1;
        vector<int> ans;
        while (firstPtr < lastPtr) {
            if (numbers.at(firstPtr) + numbers.at(lastPtr) == target) {
                ans.push_back(firstPtr + 1);
                ans.push_back(lastPtr + 1);
                break;
            } else if (numbers.at(firstPtr) + numbers.at(lastPtr) < target) {
                firstPtr++;
            } else {
                lastPtr--;
            }
        }
        return ans;
    }
};