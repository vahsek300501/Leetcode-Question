class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x != 0 || y != 0) {
            int lastBitFirst = x%2;
            int lastBitSecond = y%2;
            if(lastBitFirst != lastBitSecond)
                count++;
            x = x/2;
            y = y/2;
        }
        return count;
    }
};