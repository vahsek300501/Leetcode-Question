class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> digitStack;
        for (int i = 0; i < num.size(); i++) {
            while (true) {
                if (k == 0)
                    break;
                if (digitStack.empty()) {
                    break;
                }
                if (digitStack.top() <= num.at(i))
                    break;
                digitStack.pop();
                k--;
            }
            digitStack.push(num.at(i));
        }
        if(k > 0) {
            while(k > 0 && digitStack.empty() == false) {
                digitStack.pop();
                k--;
            }
        }
        string ans;
        if(digitStack.empty()) {
            ans += '0';
            return ans;
        }
        while (!digitStack.empty()) {
            ans += digitStack.top();
            digitStack.pop();
        }
        reverse(ans.begin(), ans.end());
        string finalAns;
        int i = 0;
        while (i < ans.size() && ans.at(i) == '0')
            i += 1;
        if (i >= ans.length()) {
            finalAns += '0';
            return finalAns;
        }
        for (int j = i; j < ans.length(); j++) {
            finalAns += ans.at(j);
        }
        return finalAns;
    }
};