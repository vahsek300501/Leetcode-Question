class Solution {
public:
    string decodeStringUtil(string s) {
        if (s.length() <= 0) {
            return "";
        }
        string ans;
        int i = 0;
        int num = 0;
        while (i < s.length()) {
            if ((int) s.at(i) - '0' >= 0 && (int) s.at(i) - '0' <= 9) {
                num = (num * 10) + ((int) s.at(i) - '0');
                i++;
                continue;
            } else if (s.at(i) == '[') {
                string tmpStr;
                i++;
                int openingBraceCount = 0;
                while (true) {
                    if (s.at(i) == ']' && openingBraceCount == 0)
                        break;
                    if (s.at(i) == '[')
                        openingBraceCount++;
                    if (s.at(i) == ']')
                        openingBraceCount--;
                    tmpStr += s.at(i);
                    i++;
                }
                string subStrProb = decodeStringUtil(tmpStr);
                for (int j = 0; j < num; j++) {
                    ans += subStrProb;
                }
                num = 0;
            } else if (s.at(i) == ']') {
                i++;
                continue;
            } else {
                ans += s.at(i);
                i++;
                continue;
            }
        }
        return ans;
    }

    string decodeString(string s) {
        string ans = decodeStringUtil(s);
        return ans;
    }
};