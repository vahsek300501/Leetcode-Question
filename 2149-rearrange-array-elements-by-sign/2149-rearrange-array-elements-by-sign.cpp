class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> negatives;
        vector<int> positives;
        for (int num : nums) {
            if (num < 0)
                negatives.push_back(num);
            else
                positives.push_back(num);
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < negatives.size() && j < positives.size()) {
            ans.push_back(positives.at(j));
            j++;
            ans.push_back(negatives.at(i));
            i++;
        }
        return ans;
    }
};