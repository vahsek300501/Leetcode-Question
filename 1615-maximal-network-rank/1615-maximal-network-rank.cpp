class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<vector<int>> graph;
        vector<vector<int>> helperGraph;
        for (int i = 0; i < n; i++) {
            vector<int> tmp2;
            graph.push_back(tmp2);
            vector<int> tmp;
            tmp.reserve(n);
            for (int j = 0; j < n; j++)
                tmp.push_back(0);
            helperGraph.push_back(tmp);
        }

        for (vector<int> edge : roads) {

            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            helperGraph[edge[0]][edge[1]] = 1;
            helperGraph[edge[1]][edge[0]] = 1;
        }
        int count = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rankCount = 0;
                if (i == j)
                    continue;
                vector<int> firstMap = graph[i];
                vector<int> secondMap = graph[j];
                rankCount += (int) firstMap.size();
                rankCount += (int) secondMap.size();
                if (helperGraph[j][i] != 0 && helperGraph[i][j] != 0)
                    rankCount--;
                count = max(count, rankCount);
            }
        }
        return count;
    }
};