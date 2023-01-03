class Solution {
public:
    int minDeletionSize(vector<string> &strs) {
        int n = (int) strs.size();
        int m = (int) strs.at(0).length();
        int colDeletedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n-1; j++) {
                if(strs[j][i] <= strs[j+1][i])
                    continue;
                else {
                    colDeletedCount++;
                    break;
                }
            }
        }
        return colDeletedCount;
    }
};