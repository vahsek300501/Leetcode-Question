class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freqMap;
        vector<bool> containsArr(26, false);
        for (char &i : s) {
            if (freqMap.find(i) == freqMap.end())
                freqMap[i] = 1;
            else
                freqMap[i] += 1;
        }
        stack<char> nonRepeatingStack;
        for (char & i : s) {
            if (nonRepeatingStack.empty()) {
                nonRepeatingStack.push(i);
                containsArr[i-'a'] = true;
                freqMap[i]--;
                continue;
            }
            if (containsArr[i-'a']) {
                freqMap[i]--;
                continue;
            }
            while (true) {
                if (nonRepeatingStack.empty())
                    break;
                if (nonRepeatingStack.top() > i && freqMap[nonRepeatingStack.top()] > 0) {
                    containsArr[nonRepeatingStack.top()-'a'] = false;
                    nonRepeatingStack.pop();
                } else
                    break;
            }
            containsArr[i-'a'] = true;
            nonRepeatingStack.push(i);
            freqMap[i]--;
        }
        string ans;
        while (!nonRepeatingStack.empty()) {
            ans += nonRepeatingStack.top();
            nonRepeatingStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};