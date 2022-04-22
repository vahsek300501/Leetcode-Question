class Solution {
public:
    int halveArray(vector<int> &nums) {
        priority_queue<double> pq;
        double sum = 0;
        double tmpSum = 0;
        for (int & num : nums) {
            pq.push(num);
            sum += (double)num;
            tmpSum += (double)num;
        }
        int count = 0;
        while (tmpSum > (sum / 2)) {
            double  top = pq.top();
            pq.pop();
            tmpSum = tmpSum - (double)top;
            tmpSum += (double)(top / 2);
            pq.push((double)(top / 2));
            count++;
        }
        return count;
    }
};