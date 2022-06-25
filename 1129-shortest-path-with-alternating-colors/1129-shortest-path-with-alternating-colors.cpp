class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        vector<vector<int>> redGraph(n, vector<int>());
        vector<vector<int>> blueGraph(n, vector<int>());
        for (auto &redEdge : redEdges) {
            redGraph[redEdge[0]].push_back(redEdge[1]);
        }
        for (auto &blueEdge : blueEdges) {
            blueGraph[blueEdge[0]].push_back(blueEdge[1]);
        }
        vector<vector<int>> ans(2, vector<int>(n, INT_MAX));
        queue<pair<int, int>> traversalQueue;
//      0 -> blue 1 -> red
        traversalQueue.push(make_pair(0, 0));
        traversalQueue.push(make_pair(0, 1));
        ans[0][0] = 0;
        ans[1][0] = 0;

        while (!traversalQueue.empty()) {
            pair<int, int> top = traversalQueue.front();
            traversalQueue.pop();
            vector<int> adjacentNodes;
            int cntColor = -1;
            if (top.second == 0) {
                adjacentNodes = redGraph.at(top.first);
                cntColor = 1;
            }
            if (top.second == 1) {
                adjacentNodes = blueGraph.at(top.first);
                cntColor = 0;
            }

            for (int adjNode : adjacentNodes) {
                if (ans[cntColor][adjNode] != INT_MAX)
                    continue;
                ans[cntColor][adjNode] = min(ans[cntColor][adjNode], ans[top.second][top.first] + 1);
                traversalQueue.push(make_pair(adjNode, cntColor));
            }
        }
        vector<int> finalAns;
        for (int i = 0; i < n; i++) {
            if (ans[0][i] == INT_MAX && ans[1][i] == INT_MAX) {
                finalAns.push_back(-1);
                continue;
            }
            finalAns.push_back(min(ans[0][i], ans[1][i]));
        }
        return finalAns;
    }
};