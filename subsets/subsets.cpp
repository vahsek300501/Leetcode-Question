class Solution {
public:
    vector<vector<int>> allSubsets;

    bool isContainsSubsets(vector<int> &arr, int num) {
        vector<int>::iterator itr;
        for (itr = arr.begin(); itr != arr.end(); itr++) {
            if (*itr == num)
                return false;
        }
        return true;
    }

    void generateAllSubsets(vector<int> &nums, int cnt, vector<int> &tmpArr) {
        allSubsets.push_back(tmpArr);
        if (cnt >= nums.size()) {
            return;
        }
        for (int i = cnt; i < nums.size(); i++) {
            if (cnt == 0) {
                tmpArr.push_back(nums.at(i));
                generateAllSubsets(nums, i + 1, tmpArr);
                tmpArr.pop_back();
                continue;
            }
            if (isContainsSubsets(tmpArr, nums.at(i))) {
                tmpArr.push_back(nums.at(i));
                generateAllSubsets(nums, i + 1, tmpArr);
                tmpArr.pop_back();
            }

        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> tmpArr;
        generateAllSubsets(nums, 0, tmpArr);
        return allSubsets;
    }
};