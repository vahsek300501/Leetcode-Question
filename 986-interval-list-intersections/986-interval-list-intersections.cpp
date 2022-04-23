class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            vector<int> tmp;
            int a = max(firstList.at(i).at(0), secondList.at(j).at(0));
            int b = min(firstList.at(i).at(1), secondList.at(j).at(1));
            if (a <= b) {
                tmp.push_back(a);
                tmp.push_back(b);
                ans.push_back(tmp);
            }
            if (firstList.at(i).at(1) < secondList.at(j).at(1))
                i++;
            else
                j++;
        }
        return ans;
    }
};