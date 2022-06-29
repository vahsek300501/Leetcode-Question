class Solution {
public:
    class Compare {
    public:
        bool operator()(pair<char, int> &first, pair<char, int> &second) {
            return first.second < second.second;
        }
    };

    string reorganizeString(string &s) {
        unordered_map<char, int> freqMap;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> mostFreqElem;

        for (char ch : s) {
            if (freqMap.find(ch) != freqMap.end()) {
                freqMap[ch] += 1;
            } else {
                freqMap[ch] = 1;
            }
        }

        auto itr = freqMap.begin();
        while (itr != freqMap.end()) {
            mostFreqElem.push(make_pair(itr->first, itr->second));
            itr++;
        }

        queue<pair<int, pair<char, int>>> waitingQueue;
        string result;
        int countTime = 0;
        while (true) {
            if (mostFreqElem.empty() && waitingQueue.empty())
                break;
            if (mostFreqElem.size() == 1 && waitingQueue.empty() && mostFreqElem.top().second > 1)
                return "";
            if (mostFreqElem.empty()) {
                countTime++;
            } else {
                pair<char, int> tmp = mostFreqElem.top();
                mostFreqElem.pop();
                countTime++;
                tmp.second--;
                result += tmp.first;
                if (tmp.second > 0) {
                    waitingQueue.push(make_pair(countTime + 1, tmp));
                }
            }
            if (!waitingQueue.empty()) {
                if (waitingQueue.front().first <= countTime) {
                    mostFreqElem.push(waitingQueue.front().second);
                    waitingQueue.pop();
                }
            }
        }
        return result;
    }
};