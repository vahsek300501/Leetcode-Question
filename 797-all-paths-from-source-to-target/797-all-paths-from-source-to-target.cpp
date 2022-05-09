class Solution {
public:
    void allPathFromSourceToTargetUtil(vector<vector<int>> &graph, vector<vector<int>> &ans, int cntNode, int endNode,
                                       vector<int> &cntPath) {
        if (cntNode == endNode) {
            cntPath.push_back(cntNode);
            ans.push_back(cntPath);
            cntPath.pop_back();
            return;
        }
        cntPath.push_back(cntNode);
        vector<int> edges = graph.at(cntNode);
        for (int edge : edges) {
            allPathFromSourceToTargetUtil(graph, ans, edge, endNode, cntPath);
        }
        cntPath.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> ans;
        vector<int> tmpPath;
        allPathFromSourceToTargetUtil(graph, ans, 0, (int) graph.size() - 1, tmpPath);
        return ans;
    }
};