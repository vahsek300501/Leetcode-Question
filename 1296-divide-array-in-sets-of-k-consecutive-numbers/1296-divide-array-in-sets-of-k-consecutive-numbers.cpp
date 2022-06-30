class Solution {
public:
    bool isPossibleDivide(vector<int> &nums, int k) {
        int n = (int) nums.size();
        unordered_map<int, int> freqMap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int i = 0; i < n; i++) {
            if (freqMap.find(nums[i]) == freqMap.end()) {
                freqMap[nums[i]] = 1;
                minHeap.push(nums[i]);
            } else {
                freqMap[nums[i]] += 1;
            }
        }

        while (!minHeap.empty()) {
            int minimum = minHeap.top();
            if (freqMap[minimum] == 0) {
                minHeap.pop();
                continue;
            }
            freqMap[minimum]--;
            int tmp = minimum + 1;
            for (int i = 0; i < k - 1; i++) {
                if (freqMap.find(tmp) != freqMap.end() && freqMap[tmp] > 0) {
                    freqMap[tmp]--;
                    tmp++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};