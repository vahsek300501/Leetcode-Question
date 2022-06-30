class Solution {
public:
    int openLock(vector<string> &deadEnds, string target) {
        unordered_map<string, bool> deadEndMap;
        set<string> visited;
        for (const string &tmp : deadEnds) {
            if (tmp == target || tmp == "0000")
                return -1;
            deadEndMap[tmp] = true;
        }
        visited.insert("0000");
        queue<pair<string, int>> traversalQueue;
        traversalQueue.push(make_pair("0000", 0));
        while (!traversalQueue.empty()) {
            pair<string, int> top = traversalQueue.front();
            traversalQueue.pop();
            if (top.first == target)
                return top.second;
            for (int i = 0; i < 4; i++) {
                string higherString = top.first.substr(0, i);
                string lowerString = top.first.substr(0, i);
                if (top.first[i] == '9')
                    higherString += '0';
                else
                    higherString += (char) ((int) top.first[i] + 1);
                if (top.first[i] == '0')
                    lowerString += '9';
                else
                    lowerString += (char) ((int) top.first[i] - 1);
                higherString += top.first.substr(i + 1);
                lowerString += top.first.substr(i + 1);
                if (visited.find(lowerString) == visited.end() && deadEndMap.find(lowerString) == deadEndMap.end()) {
                    visited.insert(lowerString);
                    traversalQueue.push(make_pair(lowerString, top.second + 1));
                }
                if (visited.find(higherString) == visited.end() && deadEndMap.find(higherString) == deadEndMap.end()) {
                    visited.insert(higherString);
                    traversalQueue.push(make_pair(higherString, top.second + 1));
                }
            }
        }
        return -1;
    }
};