class Solution {
public:
    vector<int> countSubTreesUtil(int n, vector<vector<int>> &graph, int cntIndex, string &label, vector<int> &ans,
                                  vector<bool> &visited) {
        visited[cntIndex] = true;
        vector<int> letterCount(26, 0);
        letterCount[label[cntIndex] - 'a'] += 1;
        for (int adjVertex : graph[cntIndex]) {
            if (visited[adjVertex])
                continue;
            vector<int> neighbourLetterCount = countSubTreesUtil(n, graph, adjVertex, label, ans, visited);
            for (int i = 0; i < 26; i++) {
                letterCount[i] += neighbourLetterCount[i];
            }
        }
        ans[cntIndex] = letterCount[label[cntIndex] - 'a'];
        return letterCount;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n, 0);
        vector<bool> visited(n, false);
        countSubTreesUtil(n, graph, 0, labels, ans, visited);
        return ans;
    }
};