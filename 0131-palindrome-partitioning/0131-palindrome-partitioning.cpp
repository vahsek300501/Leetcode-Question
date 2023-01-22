class Solution {
public:
    vector<vector<string>> palindromicSubstrings;

    bool isPalindrome(string arr) {
        if (arr.length() <= 0)
            return false;
        if (arr.length() == 1)
            return true;
        int s = 0, e = arr.length() - 1;

        while (s <= e) {
            if (arr.at(s) == arr.at(e)) {
                s++;
                e--;
            } else {
                return false;
            }
        }
        return true;
    }

    void getAllPalindromicSubstrings(string s, int crntIndex, vector<string>& crntStr) {
        if (crntIndex >= s.length()) {
//            bool found = true;
//            for(int i = 0;i<crntStr.size();i++) {
//                if(isPalindrome(crntStr.at(i)))
//                    continue;
//                else {
//                    found = false;
//                    break;
//                }
//            }
//            if(found) {
//                palindromicSubstrings.push_back(crntStr);
//            }
            palindromicSubstrings.push_back(crntStr);
            return;
        }
        string tmp = "";
        for(int i = crntIndex;i<s.length();i++) {
            tmp += char(s.at(i));
            if(isPalindrome(tmp)) {
                crntStr.push_back(tmp);
                getAllPalindromicSubstrings(s,i+1,crntStr);
                crntStr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> tmpStr;
        getAllPalindromicSubstrings(s,0,tmpStr);
        return palindromicSubstrings;
    }
};