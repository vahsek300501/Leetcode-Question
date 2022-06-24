class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (int i = 0; i < n; i++) {
            if (i == headID)
                continue;
            graph[manager[i]].push_back(make_pair(i, informTime[i]));
        }
        queue<pair<int, int>> traversalQueue;
        traversalQueue.push(make_pair(headID, informTime[headID]));
        int maxi = INT_MIN;
        while (!traversalQueue.empty()) {
            pair<int, int> top = traversalQueue.front();
            traversalQueue.pop();
            if (graph[top.first].empty()) {
                maxi = max(maxi, top.second);
                continue;
            }
            vector<pair<int, int>> adjacentNodes = graph[top.first];
            for (pair<int, int> adjNode : adjacentNodes) {
                traversalQueue.push(make_pair(adjNode.first, adjNode.second + top.second));
            }
        }
        return maxi;
    }
};