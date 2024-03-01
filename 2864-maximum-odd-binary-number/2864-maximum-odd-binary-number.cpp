class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        ans.append(s.length(), '0');
        int countOne = 0;
        for (char ch: s) {
            if (ch == '1') {
                countOne++;
            }
        }
        ans[ans.length() - 1] = '1';
        countOne--;
        for (int i = 0; i < s.length() - 1 && countOne != 0; i++, countOne--) {
            ans[i] = '1';
        }
        return ans;
    }
};