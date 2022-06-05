class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0)
            return true;
        int cSqrt = (int) sqrt(c);
        for (int i = 0; i <= cSqrt; i++) {
            double tmp = sqrt((double) c - ((double) (pow(i, 2))));
            if (tmp - (int) tmp == 0)
                return true;
        }
        return false;
    }
};