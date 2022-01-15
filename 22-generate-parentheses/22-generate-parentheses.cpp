class Solution {
public:
    void generateAllParenthesisUtil(int n, int cntOpen, int cntClose, string braces,        vector<string> &ans) {
        if (cntOpen == n && cntClose == n) {
            ans.push_back(braces);
            return;
        }
        if (cntOpen < n) {
            generateAllParenthesisUtil(n, cntOpen + 1, cntClose, braces + '(', ans);
        }
        if (cntClose < n && cntClose < cntOpen) {
            generateAllParenthesisUtil(n, cntOpen, cntClose + 1, braces + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateAllParenthesisUtil(n, 0, 0, "", ans);
        return ans;
    }
};