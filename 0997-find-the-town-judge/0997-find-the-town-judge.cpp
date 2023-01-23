class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust) {
        vector<vector<int>> inNodes(n, vector<int>());
        vector<vector<int>> outNodes(n, vector<int>());
        for (auto &i : trust) {
            inNodes[i[0] - 1].push_back(i[1] - 1);
            outNodes[i[1] - 1].push_back(i[0] - 1);
        }
        int judge = -1;
        for (int i = 0; i < n; i++) {
            if (outNodes[i].size() == n - 1 && inNodes[i].empty()) {
                judge = i + 1;
                break;
            }
        }
        return judge;
    }
};