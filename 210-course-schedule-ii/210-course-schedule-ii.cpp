class Solution {
public:
    bool
    detectCycleDirectedDFS(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVisited, int cntIndex) {
        visited[cntIndex] = true;
        dfsVisited[cntIndex] = true;
        vector<int> edges = graph[cntIndex];
        for (int edge : edges) {
            if (visited[edge]) {
                if (dfsVisited[edge])
                    return true;
            } else {
                bool isCycleFound = detectCycleDirectedDFS(graph, visited, dfsVisited, edge);
                if (isCycleFound)
                    return true;
            }
        }
        dfsVisited[cntIndex] = false;
        return false;
    }

     bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph;
        for (int i = 0; i < numCourses; i++) {
            vector<int> tmp;
            graph.push_back(tmp);
        }
        for (auto &prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> dfsVisited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && detectCycleDirectedDFS(graph, visited, dfsVisited, i))
                return false;
        }
        return true;
    }

//  Topological Sort Using DFS
    void
    topologicalSortDFS(vector<vector<int>> &graph, int n, vector<bool> &visited, stack<int> &topologicalSortedStack,
                       int cntInd) {
        visited[cntInd] = true;
        vector<int> adjacentEdges = graph.at(cntInd);
        for (int edge : adjacentEdges) {
            if (!visited[edge]) {
                topologicalSortDFS(graph, n, visited, topologicalSortedStack, edge);
            }
        }
        topologicalSortedStack.push(cntInd);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        bool canFinishCourses = canFinish(numCourses, prerequisites);
        vector<int> ans;
        if (!canFinishCourses)
            return ans;
        vector<vector<int>> graph;
        for (int i = 0; i < numCourses; i++) {
            vector<int> tmp;
            graph.push_back(tmp);
        }
        for (auto &prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<bool> visited(numCourses, false);
        stack<int> topologicalSorted;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                topologicalSortDFS(graph, numCourses, visited, topologicalSorted, i);
            }
        }

        while (!topologicalSorted.empty()) {
            ans.push_back(topologicalSorted.top());
            topologicalSorted.pop();
        }
        return ans;
    }
};