class UnionFindAlgorithm {
private:
    int numberOfElements;
    vector<int> rank;
    vector<int> parent;
public:
    UnionFindAlgorithm(int p_numElements);

    int findParent(int node);

    void findUnion(int node1, int node2);

};

UnionFindAlgorithm::UnionFindAlgorithm(int p_numElements) {
    this->numberOfElements = p_numElements;
    for (int i = 0; i < p_numElements; i++) {
        this->parent.push_back(i);
        this->rank.push_back(0);
    }
}

int UnionFindAlgorithm::findParent(int node) {
    if (this->parent[node] == node)
        return node;
    return this->parent[node] = findParent(this->parent[node]);
}

void UnionFindAlgorithm::findUnion(int node1, int node2) {
    node1 = this->findParent(node1);
    node2 = this->findParent(node2);

    if (this->rank[node1] > this->rank[node2]) {
        this->parent[node2] = node1;
    } else if (this->rank[node1] < this->rank[node2]) {
        this->parent[node1] = node2;
    } else {
        this->parent[node2] = node1;
        rank[node1]++;
    }
}
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        UnionFindAlgorithm nodesUnion((int) edges.size());
        vector<int> ans;
        for (vector<int> edge : edges) {
            int parentFirst = nodesUnion.findParent(edge[0] - 1);
            int parentSecond = nodesUnion.findParent(edge[1] - 1);
            if (parentFirst != parentSecond) {
                nodesUnion.findUnion(edge[0] - 1, edge[1] - 1);
            } else {
                ans.push_back(edge[0]);
                ans.push_back(edge[1]);
            }
        }
        return ans;
    }
};