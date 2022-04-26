class Solution {
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        vector<bool> ans;
        
        for (const string &queryString : queries) {
            bool isAdded = false;
            int cntPatternInd = 0;
            int cntQueryInd = 0;
            while (cntQueryInd < queryString.length() && cntPatternInd < pattern.length()) {
                if (queryString.at(cntQueryInd) == pattern.at(cntPatternInd)) {
                    cntQueryInd++;
                    cntPatternInd++;
                } else {
                    if (isupper(queryString.at(cntQueryInd))) {
                        ans.push_back(false);
                        isAdded = true;
                        break;
                    } else {
                        cntQueryInd++;
                    }
                }
            }
            if(isAdded) {
                continue;
            }
            if (cntPatternInd >= pattern.length()) {
                bool found = true;
                for (int i = cntQueryInd; i < queryString.length(); i++) {
                    if (isupper(queryString.at(i))) {
                        found = false;
                        break;
                    }
                }
                if (found)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};