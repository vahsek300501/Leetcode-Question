class Solution {
public:
    void findJointElements(vector<vector<int>> &graph, int cntInd, vector<bool> &visited) {
        if (visited[cntInd])
            return;
        visited[cntInd] = true;
        for (int i = 0; i < graph.at(cntInd).size(); i++) {
            if (cntInd == i)
                continue;
            if (graph.at(cntInd).at(i) == 1 && !visited[i])
                findJointElements(graph, i, visited);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count = 0;
        for (int i = 0; i < (int) isConnected.size(); i++) {
            if (!visited[i]) {
                findJointElements(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};