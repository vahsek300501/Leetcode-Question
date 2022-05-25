class Solution {
public:
    bool dfsSafeState(vector<vector<int>> &graph, int cntIndex, unordered_map<int, bool> &safeState) {
        if (safeState.find(cntIndex) != safeState.end()) {
            if (safeState[cntIndex])
                return true;
            return false;
        }
        safeState[cntIndex] = false;
        vector<int> adjacentNodesList = graph[cntIndex];
        for (int adjacentNode : adjacentNodesList) {
            bool isAdjacentNodeSafe = dfsSafeState(graph, adjacentNode, safeState);
            if (!isAdjacentNodeSafe)
                return false;
        }
        safeState[cntIndex] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        unordered_map<int, bool> nodeStates;
        int n = (int) graph.size();
        for (int i = 0; i < n; i++) {
            if (nodeStates.find(i) == nodeStates.end()) {
                dfsSafeState(graph, i, nodeStates);
            }
        }
        auto itr = nodeStates.begin();
        vector<int> finalSafeStates;
        while (itr != nodeStates.end()) {
            if (itr->second)
                finalSafeStates.push_back(itr->first);
            itr++;
        }
        sort(finalSafeStates.begin(), finalSafeStates.end());
        return finalSafeStates;
    }
};