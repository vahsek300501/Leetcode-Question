class Solution {
public:
    void dfsDisconnected(vector<vector<int>> &graph, vector<bool> &visited, int cntNode) {
        if (visited[cntNode])
            return;

        vector<int> tmp = graph[cntNode];
        visited[cntNode] = true;

        for (int edge : tmp) {
            dfsDisconnected(graph, visited, edge);
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections) {
        int connectionCount = (int) connections.size();
        if (connectionCount < n - 1)
            return -1;

        vector<vector<int>> graph;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            graph.push_back(tmp);
        }
        for (vector<int> edge:connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfsDisconnected(graph, visited, i);
            }
        }
        return count-1;
    }
};