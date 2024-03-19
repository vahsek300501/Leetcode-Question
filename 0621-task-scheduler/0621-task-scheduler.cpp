class Solution {
public:
    class Compare {
    public:
        bool operator()(pair<char, int> &first, pair<char, int> &second) {
            return first.second < second.second;
        }
    };

    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> freqMap;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> mostFreqElem;

        for (char tmpTask : tasks) {
            if (freqMap.find(tmpTask) != freqMap.end()) {
                freqMap[tmpTask] += 1;
            } else {
                freqMap[tmpTask] = 1;
            }
        }

        auto itr = freqMap.begin();
        while (itr != freqMap.end()) {
            mostFreqElem.push(make_pair(itr->first, itr->second));
            itr++;
        }

        queue<pair<int, pair<char, int>>> waitingQueue;
        int countTime = 0;

        while (true) {
            if (mostFreqElem.empty() && waitingQueue.empty())
                break;
            if (mostFreqElem.empty()) {
                countTime++;
            } else {
                pair<char, int> tmp = mostFreqElem.top();
                mostFreqElem.pop();
                countTime++;
                tmp.second--;
                if (tmp.second > 0) {
                    waitingQueue.push(make_pair(countTime + n, tmp));
                }
            }
            if (!waitingQueue.empty()) {
                if (waitingQueue.front().first <= countTime) {
                    mostFreqElem.push(waitingQueue.front().second);
                    waitingQueue.pop();
                }
            }
        }
        return countTime;
    }
};