class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<int>> graph;
        unordered_map<int, unordered_map<int, int>> initialEdges;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            graph.push_back(tmp);
        }
        for (vector<int> edge:connections) {
            graph.at(edge.at(0)).push_back(edge.at(1));
            graph.at(edge.at(1)).push_back(edge.at(0));
            initialEdges[edge.at(0)][edge.at(1)] = 1;
        }

        int count = 0;
        queue<int> traversalQueue;
        traversalQueue.push(0);
        visited[0] = true;

        while (!traversalQueue.empty()) {
            int top = traversalQueue.front();
            traversalQueue.pop();
            vector<int> tmp = graph[top];
            for (int vertex: tmp) {
                if (!visited[vertex]) {
                    traversalQueue.push(vertex);
                    visited[vertex] = true;
                    if (initialEdges.find(top) != initialEdges.end() &&
                        initialEdges[top].find(vertex) != initialEdges[top].end())
                        count++;
                }
            }
        }
        
        return count;
    }
};