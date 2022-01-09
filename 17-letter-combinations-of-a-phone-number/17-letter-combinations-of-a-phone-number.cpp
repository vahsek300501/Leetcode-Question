class Solution {
public:
    void
    letterCombinationUtil(string digit, int cntIndex, vector<string> &ans, unordered_map<char, vector<char>> &keypad,
                          string ansStr) {
        if (cntIndex >= digit.length()) {
            ans.push_back(ansStr);
            return;
        }
        vector<char> tmpArr = keypad[digit.at(cntIndex)];
        for (char i : tmpArr) {
            letterCombinationUtil(digit, cntIndex + 1, ans, keypad, ansStr + i);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return vector<string>();
        unordered_map<char, vector<char>> keypad;
        keypad['2'] = {'a', 'b', 'c'};
        keypad['3'] = {'d', 'e', 'f'};
        keypad['4'] = {'g', 'h', 'i'};
        keypad['5'] = {'j', 'k', 'l'};
        keypad['6'] = {'m', 'n', 'o'};
        keypad['7'] = {'p', 'q', 'r', 's'};
        keypad['8'] = {'t', 'u', 'v'};
        keypad['9'] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        letterCombinationUtil(digits, 0, ans, keypad, "");
        return ans;
    }
};