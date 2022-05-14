class Solution {
public:
    static void bfsTimeToReach(int **graph, int *visited, int n, int k) {
        queue<pair<int, int>> traversalQueue;
        traversalQueue.push(make_pair(k, 0));
        visited[k] = 0;
        while (!traversalQueue.empty()) {
            pair<int, int> top = traversalQueue.front();
            traversalQueue.pop();
            for (int i = 0; i < n; i++) {
                if (graph[top.first][i] == -1)
                    continue;
                if (visited[i] != -1 && visited[i] <= top.second + graph[top.first][i])
                    continue;
                traversalQueue.push(make_pair(i, top.second + graph[top.first][i]));
                visited[i] = top.second + graph[top.first][i];
            }
        }
    }
    

    int networkDelayTime(vector<vector<int>> &edges, int n, int k) {
        int **graph = new int *[n];
        int *visited = new int[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new int[n];
            visited[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = -1;
            }
        }
        for (vector<int> edge: edges) {
            graph[edge.at(0) - 1][edge.at(1) - 1] = edge.at(2);
        }
        bfsTimeToReach(graph, visited, n, k - 1);
        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1)
                return -1;
            if (visited[i] > maxVal)
                maxVal = visited[i];
        }
        return maxVal;
    }
};