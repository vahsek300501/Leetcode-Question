#define MOD 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long int maxHorizontal = abs(0 - (long long int)verticalCuts[0]);
        long long int maxVertical = abs(0 - (long long int)horizontalCuts[0]);
        for (int i = 1; i < (int) horizontalCuts.size(); i++) {
            maxVertical = max(maxVertical, (long long int) abs(horizontalCuts[i] - horizontalCuts[i - 1]));
        }
        for (int i = 1; i < (int) verticalCuts.size(); i++) {
            maxHorizontal = max(maxHorizontal, (long long int) abs(verticalCuts[i] - verticalCuts[i - 1]));
        }
        maxVertical = max(maxVertical,(long long int) abs(h - horizontalCuts[horizontalCuts.size() - 1]));
        maxHorizontal = max(maxHorizontal,(long long int) abs(w - verticalCuts[verticalCuts.size() - 1]));
        return ((maxVertical % MOD) * (maxHorizontal % MOD)) % MOD;
    }
};