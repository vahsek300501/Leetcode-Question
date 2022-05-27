class Solution {
public:
    void topologicalSortDFSAncestors(vector<vector<int>> &graph, int n, vector<bool> &visited,
                                     stack<int> &topologicalSortedStack,
                                     int cntInd) {
        visited[cntInd] = true;
        vector<int> adjacentEdges = graph.at(cntInd);
        for (int edge : adjacentEdges) {
            if (!visited[edge]) {
                topologicalSortDFSAncestors(graph, n, visited, topologicalSortedStack, edge);
            }
        }
        topologicalSortedStack.push(cntInd);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph;
        vector<unordered_map<int, bool>> tmpAnsMap;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            unordered_map<int, bool> tmpFound;
            vector<int> tmp;
            vector<int> tmp2;
            graph.push_back(tmp);
            ans.push_back(tmp2);
            tmpAnsMap.push_back(tmpFound);
        }
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(n, false);
        stack<int> sortedStack;
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                topologicalSortDFSAncestors(graph, n, visited, sortedStack, i);
        }

        while (!sortedStack.empty()) {
            int top = sortedStack.top();
            sortedStack.pop();
            vector<int> adjacentVertices = graph[top];
            vector<int> prevAncestors = ans[top];
            for (int adjVertex : adjacentVertices) {
                for (int prevAncestor : prevAncestors) {
                    if (tmpAnsMap[adjVertex].find(prevAncestor) == tmpAnsMap[adjVertex].end()) {
                        ans[adjVertex].push_back(prevAncestor);
                        tmpAnsMap[adjVertex][prevAncestor] = true;
                    }
                }
                ans[adjVertex].push_back(top);
                tmpAnsMap[adjVertex][top] = true;
            }
        }

        for (auto & an : ans) {
            if (an.empty())
                continue;
            sort(an.begin(), an.end());
        }
        return ans;
    }
};