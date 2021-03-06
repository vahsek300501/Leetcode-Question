class Solution {
public:
    vector <vector<int>> threeSum(vector<int> &nums) {
        vector <vector<int>> ans;
        if (nums.size() == 1 || nums.size() == 2)
            return ans;

        set <vector<int>> ansSet;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int firstNum = nums[i];
            int startPtr = i + 1;
            int endPtr = (int) nums.size() - 1;
            while (startPtr < endPtr) {
                if (startPtr != i + 1 && nums[startPtr] == nums[startPtr - 1]) {
                    startPtr++;
                    continue;
                }
                int secondNum = nums[startPtr];
                int thirdNum = nums[endPtr];
                int sum = firstNum + secondNum + thirdNum;
                if (sum == 0) {
                    vector<int> tmp = {firstNum, secondNum, thirdNum};
//                    ansSet.insert(tmp);
                    ans.push_back(tmp);
                    startPtr++;
                    endPtr--;
                } else if (sum < 0) {
                    startPtr++;
                } else {
                    endPtr--;
                }
            }
        }

//        auto itr = ansSet.begin();
//        while (itr != ansSet.end()) {
//            ans.push_back(*itr);
//            itr++;
//        }
        return ans;
    }
};