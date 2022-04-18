class Solution {
public:
    bool isValid(string s) {
        stack<char> checkABCStack;
        for (char &i : s) {
            if (i == 'c') {
                if (checkABCStack.empty())
                    return false;
                char top = checkABCStack.top();
                if (top != 'b')
                    return false;
                checkABCStack.pop();
                if(checkABCStack.empty())
                    return false;
                top = checkABCStack.top();
                if (top != 'a')
                    return false;
                checkABCStack.pop();
            } else {
                checkABCStack.push(i);
            }
        }
        if (checkABCStack.empty())
            return true;
        return false;
    }
};