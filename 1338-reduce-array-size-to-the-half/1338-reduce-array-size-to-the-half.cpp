class Solution {
public:
    class Compare3 {
    public:
        bool operator()(pair<int, int> first, pair<int, int> second) {
            return first.second < second.second;
        }
    };

    int minSetSize(vector<int> &arr) {
        int n = (int) arr.size();
        unordered_map<int, int> freqMap;
        for (int i = 0; i < n; i++) {
            if (freqMap.find(arr[i]) == freqMap.end()) {
                freqMap[arr[i]] = 1;
            } else {
                freqMap[arr[i]] += 1;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare3> maxFreqHeap;

        auto itr = freqMap.begin();
        while (itr != freqMap.end()) {
            maxFreqHeap.push(make_pair(itr->first, itr->second));
            itr++;
        }
        int cntTotalCount = (int) arr.size();
        int minSetSize = 0;
        while (!maxFreqHeap.empty()) {
            if (cntTotalCount <= (n / 2)) {
                break;
            }
            pair<int, int> top = maxFreqHeap.top();
            maxFreqHeap.pop();
            minSetSize++;
            cntTotalCount = cntTotalCount - top.second;
        }
        return minSetSize;
    }
};