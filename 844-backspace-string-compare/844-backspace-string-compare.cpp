class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        string s2 = "";
        int i = 0;
        while(i<s.length()) {
            if(s.at(i) == '#') {
                if(s1.empty()) {
                    i += 1;
                    continue;
                }
                    
                s1.pop_back();
            } else {
                s1 += s.at(i);    
            }
            i+=1;
        }
        int j = 0;
        while(j < t.length()) {
            if(t.at(j) == '#') {
                if(s2.empty()) {
                    j+=1;
                    continue;
                }
                    
                s2.pop_back();
            } else
                s2 += t.at(j);
            j+=1;
        }
        return s1 == s2;
    }
};