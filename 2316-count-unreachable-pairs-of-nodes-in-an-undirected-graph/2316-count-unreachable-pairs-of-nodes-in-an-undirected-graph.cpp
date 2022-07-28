class Solution {
public:
    void getConnectedComponents(vector<vector<int>> &graph, int cntVertex, vector<bool> &visited, int &countConnected) {
        countConnected += 1;
        visited[cntVertex] = true;
        for (int adjVertex : graph[cntVertex]) {
            if(!visited[adjVertex])
                getConnectedComponents(graph, adjVertex, visited, countConnected);
        }
    }

    long long countPairs(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        long long int ans = 0;
        int remainingVertices = n;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int cntConnected = 0;
                getConnectedComponents(graph, i, visited, cntConnected);
                ans += (((long long int)(remainingVertices - cntConnected)) * ((long long int)cntConnected));
                remainingVertices = remainingVertices - cntConnected;
            }
        }
        return ans;
    }
};