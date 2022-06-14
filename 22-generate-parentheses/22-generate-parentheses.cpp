class Solution {
public:
    void
    generateParenthesisUtil(int n, int cntOpeningBrace, int cntClosingBrace, vector<string> &ans, string cntString) {
        if (cntOpeningBrace == n && cntClosingBrace == n) {
            ans.push_back(cntString);
            return;
        }
        if (cntOpeningBrace <= n) {
            generateParenthesisUtil(n, cntOpeningBrace + 1, cntClosingBrace, ans, cntString + '(');
        }
        if (cntClosingBrace <= n && cntClosingBrace < cntOpeningBrace) {
            generateParenthesisUtil(n, cntOpeningBrace, cntClosingBrace+1, ans, cntString + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesisUtil(n, 0, 0, ans, "");
        return ans;
    }
};