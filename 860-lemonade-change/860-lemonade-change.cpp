class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int cntFive = 0;
        int cntTen = 0;
        int cntTwenty = 0;
        for (int tmpBill : bills) {
            if (tmpBill == 5)
                cntFive++;
            else if (tmpBill == 10) {
                if (cntFive <= 0)
                    return false;
                cntTen++;
                cntFive--;
            } else {
                if (cntTen > 0) {
                    if (cntFive > 0) {
                        cntTwenty++;
                        cntTen--;
                        cntFive--;
                        continue;
                    }
                } if (cntFive >= 3) {
                    cntTwenty++;
                    cntFive = cntFive - 3;
                    continue;
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};