class Solution {
public:
    int compareStrings(string &s1, string &s2) {
        int count = 0;
        int i = 0;
        int j = 0;
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
                continue;
            }
            count++;
            i++;
            j++;
        }
        return count;
    }

    int minMutation(string start, string end, vector<string> &bank) {
        if (start == end)
            return 0;
        queue<pair<string, int>> traversalQueue;
        vector<bool> visited(bank.size(), false);
        traversalQueue.push(make_pair(start, 0));
        while (!traversalQueue.empty()) {
            pair<string, int> top = traversalQueue.front();
            traversalQueue.pop();
            if (top.first == end)
                return top.second;
            for (int i = 0; i < bank.size(); i++) {
                if (visited[i])
                    continue;
                if (compareStrings(top.first, bank[i]) == 1) {
                    traversalQueue.push(make_pair(bank[i], top.second + 1));
                    visited[i] = true;
                }
            }
        }
        return -1;
    }
};