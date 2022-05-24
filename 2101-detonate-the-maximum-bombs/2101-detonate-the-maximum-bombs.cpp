class Solution {
public:
    double eulerDistance(int x1, int y1, int x2, int y2) {
        double distance = ((double) pow(x2 - x1, 2)) + ((double) pow(y2 - y1, 2));
        return sqrt(distance);
    }
    
    int countMaxDetonations(vector<vector<int>> &graph, int cntIndex, vector<bool> &visited) {
        visited[cntIndex] = true;
        int cntDetonations = 1;
        for (int adjNode : graph[cntIndex]) {
            if (!visited[adjNode]) {
                cntDetonations += countMaxDetonations(graph, adjNode, visited);
            }
        }
        return cntDetonations;
    }

    int maximumDetonation(vector<vector<int>> &bombs) {
        int n = (int) bombs.size();
        vector<vector<int>> graph;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            graph.push_back(tmp);
        }

        for (int i = 0; i < n; i++) {
            vector<int> cntBomb = bombs.at(i);
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                double dist = eulerDistance(cntBomb[0], cntBomb[1], bombs[j][0], bombs[j][1]);
                if (dist <= cntBomb[2]) {
                    graph[i].push_back(j);
                }

            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int tmpAns = countMaxDetonations(graph, i, visited);
            ans = max(ans, tmpAns);
        }
        return ans;
    }
};