class Solution {
public:
    bool possibleBiPartitionUtil(vector<vector<int>> &graph, int n, int startInd, int cntColor, vector<bool> &visited,
                                 vector<int> &colorArr) {
        queue<int> traversalQueue;

        traversalQueue.push(startInd);
        colorArr[startInd] = cntColor;
        visited[startInd] = true;

        while (!traversalQueue.empty()) {
            int top = traversalQueue.front();
            traversalQueue.pop();
            int nextColor = colorArr[top] == 1 ? 0 : 1;
            vector<int> adjacentVertexList = graph[top];
            for (int adjVertex : adjacentVertexList) {
                if (!visited[adjVertex]) {
                    traversalQueue.push(adjVertex);
                    visited[adjVertex] = true;
                    colorArr[adjVertex] = nextColor;
                } else if (colorArr[adjVertex] == colorArr[top])
                    return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<vector<int>> graph;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            graph.push_back(tmp);
        }
        for (auto &dislike : dislikes) {
            graph[dislike[0] - 1].push_back(dislike[1] - 1);
            graph[dislike[1] - 1].push_back(dislike[0] - 1);
        }

        vector<bool> visited(n, false);
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bool found = possibleBiPartitionUtil(graph, n, i, 0, visited, color);
                if (!found)
                    return false;
            }
        }
        return true;
    }
};