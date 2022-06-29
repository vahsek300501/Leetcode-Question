class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = (int) gas.size();
        int sumGas = 0;
        int sumCost = 0;
        vector<int> diffArr;
        for (int i = 0; i < n; i++) {
            sumGas += gas[i];
            sumCost += cost[i];
            diffArr.push_back(gas[i] - cost[i]);
        }
        if (sumGas < sumCost)
            return -1;

        int index = 0;
        int cntSum = 0;

        for (int i = 0; i < n; i++) {
            cntSum += diffArr[i];
            if (cntSum < 0) {
                index = i + 1;
                cntSum = 0;
            }
        }
        return index;
    }
};