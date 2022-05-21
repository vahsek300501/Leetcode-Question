class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        queue<pair<int, int>> traversalQueue;
        vector<bool> visited(graph.size(), false);
        vector<int> colorArr(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                traversalQueue.push(make_pair(i, 0));
                visited[i] = true;
                colorArr[i] = 0;

                while (!traversalQueue.empty()) {
                    pair<int, int> top = traversalQueue.front();
                    traversalQueue.pop();
                    vector<int> edges = graph[top.first];
                    int color = top.second == 0 ? 1 : 0;
                    for (int edge:edges) {
                        if (!visited[edge]) {
                            traversalQueue.push(make_pair(edge, color));
                            visited[edge] = true;
                            colorArr[edge] = color;
                            continue;
                        } else if (colorArr[edge] == top.second)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};