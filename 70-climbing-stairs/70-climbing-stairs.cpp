class Solution {
public:
    int climbStairsDPSpaceOptimized(int n) {
        int singleStepPrev = 1;
        int doubleStepPrev = 0;
        for (int i = 1; i <= n; i++) {
            int tmpAns = singleStepPrev + doubleStepPrev;
            doubleStepPrev = singleStepPrev;
            singleStepPrev = tmpAns;
        }
        return singleStepPrev;
    }
    int climbStairs(int n) {
        return climbStairsDPSpaceOptimized(n);   
    }
};