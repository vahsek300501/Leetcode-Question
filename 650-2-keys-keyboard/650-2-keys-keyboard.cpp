class Solution {
public:
    int minStepsRecursive(int n, int cntSteps, int cntCopiedCount, int cntScreenCount) {
        if (cntScreenCount == n)
            return cntSteps;
        if (cntSteps >= n)
            return INT_MAX;
        if (cntScreenCount > n)
            return INT_MAX;

        if (cntSteps == 0) {
            return minStepsRecursive(n, cntSteps + 1, cntScreenCount, cntScreenCount);
        }
        int first = INT_MAX;
        if(cntCopiedCount != cntScreenCount)
            first = minStepsRecursive(n, cntSteps + 1, cntScreenCount, cntScreenCount);
        int second = minStepsRecursive(n, cntSteps + 1, cntCopiedCount, cntScreenCount + cntCopiedCount);
        return min(first, second);
    }

    int minSteps(int n) {
        return minStepsRecursive(n, 0, 0, 1);
    }
};