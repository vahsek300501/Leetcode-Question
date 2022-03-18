class Solution {
public:
    int numTreesUtilRecursion(int s, int e) {
        if (s > e)
            return 0;
        if (s == e)
            return 1;

        int tmpAns = 0;
        for (int i = s; i <= e; i++) {
            int leftPossibleSubtrees = numTreesUtilRecursion(s, i - 1);
            int rightPossibleSubtrees = numTreesUtilRecursion(i + 1, e);
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

    int numTreesUtilMemoization(int s, int e, int **dp) {
        if (s > e)
            return 0;
        if (s == e)
            return 1;
        if (dp[s][e] != -1)
            return dp[s][e];

        int tmpAns = 0;
        for (int i = s; i <= e; i++) {
            int leftPossibleSubtrees = numTreesUtilMemoization(s, i - 1, dp);
            int rightPossibleSubtrees = numTreesUtilMemoization(i + 1, e, dp);
            if (leftPossibleSubtrees == 0 && rightPossibleSubtrees == 0)
                continue;
            else if (leftPossibleSubtrees == 0 && rightPossibleSubtrees != 0)
                tmpAns += rightPossibleSubtrees;
            else if (leftPossibleSubtrees != 0 && rightPossibleSubtrees == 0)
                tmpAns += leftPossibleSubtrees;
            else
                tmpAns += (leftPossibleSubtrees * rightPossibleSubtrees);
        }
        dp[s][e] = tmpAns;
        return tmpAns;
    }

    int numTrees(int n) {
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = new int[n + 1];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        int uniqueBSTs = numTreesUtilMemoization(1, n, dp);
        for (int i = 0; i <= n; i++) {
            delete[] dp[i];
        }
        delete[] dp;
        return uniqueBSTs;
    }
};