class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapital = 0;
        for(int i =0;i<word.length();i++) {
            if(isupper(word.at(i)))
                countCapital++;
        }
        if(countCapital == 0)
            return true;
        if(countCapital == word.length())
            return true;
        if(countCapital == 1 && isupper(word.at(0)))
            return true;
        return false;
    }
};