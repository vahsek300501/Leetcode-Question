class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        ans.append(s.length(), '0');
        int countOne = (int) count(s.begin(), s.end(), '1') - 1;
        ans[ans.length() - 1] = '1';
        for (int i = 0; i < s.length() - 1 && countOne != 0; i++, countOne--) {
            ans[i] = '1';
        }
        return ans;
    }
};