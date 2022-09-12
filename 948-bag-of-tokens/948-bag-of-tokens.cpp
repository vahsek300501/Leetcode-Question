class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        if(tokens.size() == 0)
            return 0;
        sort(tokens.begin(), tokens.end());
        int cntScore = 0;
        long long int cntPower = power;
        int firstPtr = 0;
        int lastPtr = (int) tokens.size() - 1;
        int maxScore = 0;
        while (firstPtr <= lastPtr) {
            if (firstPtr == lastPtr) {
                if (cntPower >= tokens[firstPtr])
                    cntScore++;
                break;
            }
            if (cntPower >= tokens[firstPtr]) {
                cntPower = cntPower - tokens[firstPtr];
                firstPtr++;
                cntScore++;
                maxScore = max(maxScore, cntScore);
                continue;
            }
            if (cntScore > 0) {
                cntPower += tokens[lastPtr];
                lastPtr--;
                cntScore--;
                continue;
            }
            if (cntScore <= 0 && cntPower < tokens[firstPtr])
                break;
        }
        return max(cntScore, maxScore);
    }
};