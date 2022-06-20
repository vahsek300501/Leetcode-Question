class Solution {
public:
    static bool comparator(string & s1 , string & s2) {
        return s1.length() > s2.length();
    }
        
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comparator);
        string ans = words[0];
        ans += "#";
        for(int i = 1;i<words.size();i++) {
            string tmp = words[i] + "#";
            int isFound = ans.find(tmp);
            if(isFound != -1)
                continue;
            ans += tmp;
        }
        return ans.length();
    }
};