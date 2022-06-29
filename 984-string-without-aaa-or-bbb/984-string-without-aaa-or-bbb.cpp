class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        int i = 0, j = 0;
        int cntACount = 0;
        int cntBCount = 0;
        while (true) {
            if (i == a && j == b)
                break;
            if(i == a && j != b) {
                ans += 'b';
                j++;
                continue;
            }
            if(j == b && i != a) {
                ans += 'a';
                i++;
                continue;
            }
            if (a - i >= b - j) {
                if (cntACount == 2) {
                    ans += 'b';
                    cntACount = 0;
                    cntBCount = 1;
                    j++;
                } else {
                    ans += 'a';
                    cntACount++;
                    i++;
                }
            } else {
                if (cntBCount == 2) {
                    ans += 'a';
                    cntACount = 1;
                    cntBCount = 0;
                    i++;
                } else {
                    ans += 'b';
                    cntBCount++;
                    j++;
                }
            }
        }
        return ans;
    }
};