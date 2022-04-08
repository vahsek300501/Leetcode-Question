class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> check;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while (l < s.length() && r < s.length()) {
            if (check.find(s.at(r)) == check.end()) {
                check.insert(s.at(r));
                if (r - l + 1 > maxLen)
                    maxLen = r - l + 1;
                r++;
            } else {
                while (true) {
                    if (s.at(l) == s.at(r)) {
                        check.erase(s.at(l));
                        l++;
                        break;
                    }
                    check.erase(s.at(l));
                    l++;
                }
            }
        }
        return maxLen;
    }
};