class Solution {
public:
    bool
    detectCycleDirectedDFS(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVisited, int cntIndex) {
        visited[cntIndex] = true;
        dfsVisited[cntIndex] = true;
        vector<int> edges = graph[cntIndex];
        for (int edge : edges) {
            if(!visited[edge]) {
                bool isCycleFound = detectCycleDirectedDFS(graph, visited, dfsVisited, edge);
                if (isCycleFound)
                    return true;
            } else if(dfsVisited[edge])
                return true;
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
};