class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int first = 0;
        int last = (int) tokens.size() - 1;
        int cntScore = 0;
        int maxScore = 0;

        while (first <= last) {
            if (first == last) {
                if (power >= tokens[first]) {
                    cntScore++;
                    maxScore = max(maxScore, cntScore);
                    power = power - tokens[first];
                }
                break;
            }
            if (power >= tokens[first]) {
                cntScore++;
                maxScore = max(maxScore, cntScore);
                power = power - tokens[first];
                first++;
            } else {
                if (cntScore > 0) {
                    power += tokens[last];
                    last--;
                    cntScore--;
                } else {
                    break;
                }
            }
        }
        return maxScore;
    }
};