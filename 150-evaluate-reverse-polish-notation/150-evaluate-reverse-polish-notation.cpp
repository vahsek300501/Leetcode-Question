class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> reversePolishStack;
        for (auto & token : tokens) {
            if (token == "+") {
                int first = reversePolishStack.top();
                reversePolishStack.pop();
                int second = reversePolishStack.top();
                reversePolishStack.pop();
                reversePolishStack.push(first + second);
            } else if (token == "-") {
                int first = reversePolishStack.top();
                reversePolishStack.pop();
                int second = reversePolishStack.top();
                reversePolishStack.pop();
                reversePolishStack.push(second - first);
            } else if (token == "*") {
                int first = reversePolishStack.top();
                reversePolishStack.pop();
                int second = reversePolishStack.top();
                reversePolishStack.pop();
                reversePolishStack.push(first * second);
            } else if (token == "/") {
                int first = reversePolishStack.top();
                reversePolishStack.pop();
                int second = reversePolishStack.top();
                reversePolishStack.pop();
                reversePolishStack.push(second / first);
            } else {
                reversePolishStack.push(stoi(token));
            }
        }
        int ans = reversePolishStack.top();
        reversePolishStack.pop();
        return ans;
    }
};