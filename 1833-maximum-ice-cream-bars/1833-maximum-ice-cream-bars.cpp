class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int cntCost : costs) {
            if (cntCost <= coins) {
                count++;
                coins = coins - cntCost;
            } else {
                break;
            }
        }
        return count;
    }
};