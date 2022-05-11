class Solution {
public:
    void countVowelUtil(int n, int cntLen, int start, int &count) {
        if (cntLen == n) {
            count++;
            return;
        }
        if (cntLen > n)
            return;

        for (int i = start; i < 5; i++) {
            countVowelUtil(n, cntLen + 1, i, count);
        }
    }

    int countVowelStrings(int n) {
        int count = 0;
        countVowelUtil(n, 0, 0, count);
        return count;
    }
};