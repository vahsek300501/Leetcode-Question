class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) {
        string ans;
        int cntIndexSpaces = 0;
        int stringCntIndex = 0;
        while (cntIndexSpaces < spaces.size() && stringCntIndex < s.length()) {
            if (stringCntIndex == spaces[cntIndexSpaces]) {
                ans += " ";
                cntIndexSpaces++;
            }
            ans += s.at(stringCntIndex);
            stringCntIndex++;
        }
        while (stringCntIndex < s.length()) {
            ans += s.at(stringCntIndex);
            stringCntIndex++;
        }
        return ans;
    }
};