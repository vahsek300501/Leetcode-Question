class Solution {
public:
    int maximum69Number (int num) {
        string cntNumStr = to_string(num);
        string finalNum;
        bool isChanged = false;
        for(char ch:cntNumStr) {
            if(ch == '9') {
                finalNum += ch;
            } else {
                if(!isChanged) {
                    finalNum += '9';
                    isChanged = true;
                    continue;
                }
                finalNum += ch;
            }
        }
        return stoi(finalNum);
    }
};