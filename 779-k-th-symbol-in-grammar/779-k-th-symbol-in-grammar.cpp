class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1)
            return 0;
        if (k <= pow(2, n - 1) / 2)
            return kthGrammar(n - 1, k);
        else
            return !kthGrammar(n - 1, k - (int) pow(2, n - 2));
    }
};