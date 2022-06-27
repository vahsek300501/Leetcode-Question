class Solution {
public:
    int minPartitions(string n) {
        int cntMax = 0;
        for(int i =0;i<n.length();i++) {
            int num = n.at(i)-'0';
            cntMax = max(cntMax,num);
        }
        return cntMax;
    }
};