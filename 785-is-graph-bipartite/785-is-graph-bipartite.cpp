class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = (int) graph.size();
        queue<pair<int, int>> traversalQueue;
        vector<int> visited(n, -1);


        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                visited[i] = 0;
                traversalQueue.push(make_pair(i, 0));
                while (!traversalQueue.empty()) {
                    pair<int, int> top = traversalQueue.front();
                    traversalQueue.pop();
                    vector<int> adjacentNodes = graph[top.first];
                    for (int node:adjacentNodes) {
                        if (visited[node] != -1) {
                            if (visited[node] == top.second)
                                return false;
                            continue;
                        }
                        visited[node] = top.second == 1 ? 0 : 1;
                        traversalQueue.push(make_pair(node, visited[node]));
                    }
                }
            }
        }
        return true;
    }
};