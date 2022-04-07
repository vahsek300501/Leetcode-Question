class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> maxHeap;
        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones.at(i));
        }
        while (maxHeap.size() > 1) {
            int firstMax = maxHeap.top();
            maxHeap.pop();
            int secondMax = maxHeap.top();
            maxHeap.pop();
            if (firstMax == secondMax)
                continue;
            else {
                maxHeap.push(firstMax - secondMax);
            }
        }
        if(maxHeap.empty())
            return 0;
        return maxHeap.top();
    }
};