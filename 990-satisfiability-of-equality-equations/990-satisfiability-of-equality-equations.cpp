class UnionFindAlgorithm {
private:
    __attribute__((unused)) int numberOfElements;
    vector<int> rank;
    vector<int> parent;
public:
    explicit UnionFindAlgorithm(int p_numElements);

    int findParent(int node);

    void findUnion(int node1, int node2);

    vector<int> getParentArr();

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

vector<int> UnionFindAlgorithm::getParentArr() {
    return this->parent;
}

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        UnionFindAlgorithm variableUnion(26);
        for (auto &equation : equations) {
            int firstNode = ((int) equation.at(0)) - 'a';
            int secondNode = ((int) equation.at(3)) - 'a';
            if (equation.at(1) == '=') {
                variableUnion.findUnion(firstNode, secondNode);
            }
        }
        for (auto &equation : equations) {
            int firstNode = ((int) equation.at(0)) - 'a';
            int secondNode = ((int) equation.at(3)) - 'a';
            if (equation.at(1) == '!') {
                if (variableUnion.findParent(firstNode) == variableUnion.findParent(secondNode))
                    return false;
            }
        }
        return true;
    }
};