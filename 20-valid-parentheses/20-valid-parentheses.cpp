class Solution {
public:
    bool isValid(string s) {
        stack<char> validate;
        for (int i = 0; i < s.length(); i++) {
            if (validate.empty() && (s.at(i) == ')' || s.at(i) == '}' || s.at(i) == ']'))
                return false;
            if (validate.empty()) {
                validate.push(s.at(i));
                continue;
            }
            if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
                validate.push(s.at(i));
                continue;
            }
            if (s.at(i) == ')' && validate.top() == '(') {
                validate.pop();
                continue;
            }
            if (s.at(i) == '}' && validate.top() == '{') {
                validate.pop();
                continue;
            }
            if (s.at(i) == ']' && validate.top() == '[') {
                validate.pop();
                continue;
            } else {
                return false;
            }
        }
        if (validate.empty())
            return true;
        return false;
    }
};