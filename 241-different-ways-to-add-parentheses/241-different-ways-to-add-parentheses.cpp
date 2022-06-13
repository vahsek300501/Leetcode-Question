class Solution {
public:
    static vector<string> breakString(string &expression) {
        vector<string> brokenString;
        string tmp;
        for (char i : expression) {
            if (i == '+') {
                brokenString.push_back(tmp);
                brokenString.emplace_back("+");
                tmp = "";
            } else if (i == '-') {
                brokenString.push_back(tmp);
                brokenString.emplace_back("-");
                tmp = "";
            } else if (i == '*') {
                brokenString.push_back(tmp);
                brokenString.emplace_back("*");
                tmp = "";
            } else {
                tmp += i;
            }
        }
        brokenString.push_back(tmp);
        return brokenString;
    }

    vector<int> diffWaysToComputeUtil(vector<string> expression) {
        if (expression.size() == 1) {
            vector<int> tmp{stoi(expression[0])};
            return tmp;
        }

        vector<int> ans;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == "+" || expression[i] == "-" || expression[i] == "*") {
                vector<string> leftHalf(expression.begin(), expression.begin() + i);
                vector<string> rightHalf(expression.begin() + i + 1, expression.end());
                vector<int> left = diffWaysToComputeUtil(leftHalf);
                vector<int> right = diffWaysToComputeUtil(rightHalf);
                for (int num1:left) {
                    for (int num2:right) {
                        if (expression[i] == "+") {
                            ans.push_back(num1 + num2);
                        } else if (expression[i] == "-") {
                            ans.push_back(num1 - num2);
                        } else {
                            ans.push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<string> expressionArr = breakString(expression);
        vector<int> ans = diffWaysToComputeUtil(expressionArr);
        return ans;
    }
};