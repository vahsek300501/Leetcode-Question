class Solution {
public:
    int getNextNumber(int n) {
        int nextNum = 0;
        while (n != 0) {
            nextNum += (int) pow(n % 10, 2);
            n = n / 10;
        }
        return nextNum;
    }

    bool isHappy(int n) {
        unordered_map<int, bool> isThere;
        while (n != 1) {
            int nextNum = getNextNumber(n);
            if (isThere.find(nextNum) != isThere.end())
                return false;
            isThere[nextNum] = true;
            n = nextNum;
        }
        return true;
    }
};