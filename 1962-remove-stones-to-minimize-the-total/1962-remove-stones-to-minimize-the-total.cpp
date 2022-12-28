class Solution {
public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int> pq;
        for (int stones: piles) {
            pq.push(stones);
        }
        while (k--) {
            int top = pq.top();
            pq.pop();
            top = top - floor(top / 2);
            pq.push(top);
        }
        
        long long int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};