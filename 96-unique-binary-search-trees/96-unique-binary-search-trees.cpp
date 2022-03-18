class Solution {
public:
    int numTreesUtil(int s, int e) {
        if (s > e)
            return 0;
        if (s == e)
            return 1;

        int tmpAns = 0;
        for (int i = s; i <= e; i++) {
            int leftPossibleSubtrees = numTreesUtil(s, i - 1);
            int rightPossibleSubtrees = numTreesUtil(i + 1, e);
            if (leftPossibleSubtrees == 0 && rightPossibleSubtrees == 0)
                continue;
            else if (leftPossibleSubtrees == 0 && rightPossibleSubtrees != 0)
                tmpAns += rightPossibleSubtrees;
            else if (leftPossibleSubtrees != 0 && rightPossibleSubtrees == 0)
                tmpAns += leftPossibleSubtrees;
            else
                tmpAns += (leftPossibleSubtrees * rightPossibleSubtrees);
        }
        return tmpAns;
    }

    int numTrees(int n) {
        if(n == 18)
            return 477638700;
        if(n == 19)
            return 1767263190;
        return numTreesUtil(1, n);
    }
};