class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        while(true) {
            if(n == 1)
                break;
            if(n % 2 != 0)
                return false;
            n = n / 2;
        }
        return true;
    }
};