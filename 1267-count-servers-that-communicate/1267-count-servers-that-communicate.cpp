class UnionFindAlgorithm {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFindAlgorithm(int p_numElements) {
        for (int i = 0; i < p_numElements; i++) {
            this->parent.push_back(i);
            this->rank.push_back(0);
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void findUnion(int firstNode, int secondNode) {
        int firstNodeParent = this->findParent(firstNode);
        int secondNodeParent = this->findParent(secondNode);
        if (rank[firstNodeParent] < rank[secondNodeParent]) {
            parent[firstNodeParent] = secondNodeParent;
        } else if (rank[firstNodeParent] > rank[secondNodeParent]) {
            parent[secondNodeParent] = firstNodeParent;
        } else {
            parent[secondNodeParent] = firstNodeParent;
            rank[firstNodeParent]++;
        }
    }

    vector<int> getParentArr() { return parent; }
};
class Solution {
public:
    int resolveParent(vector<int> &parentArr, int node) {
        if (node == parentArr[node])
            return node;
        return parentArr[node] = resolveParent(parentArr, parentArr[node]);
    }

   int countServers(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        int m = (int) grid.at(0).size();
        vector<pair<int, pair<int, int>>> serverPosition;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    serverPosition.emplace_back(count++, make_pair(i, j));
                }
            }
        }

        int serverCount = (int) serverPosition.size();
        UnionFindAlgorithm serverUnion(serverCount);
        for (int i = 0; i < serverCount; i++) {
            for (int j = i + 1; j < serverCount; j++) {
                if (serverPosition[j].second.first == serverPosition.at(i).second.first ||
                    serverPosition[j].second.second == serverPosition.at(i).second.second) {
                    serverUnion.findUnion(serverPosition.at(i).first, serverPosition[j].first);
                }
            }
        }

        vector<int> parentArr = serverUnion.getParentArr();
        for (int i = 0; i < serverCount; i++) {
            resolveParent(parentArr, i);
        }

        unordered_map<int, int> freqMap;
        for (int & i : parentArr) {
            if (freqMap.find(i) != freqMap.end())
                freqMap[i] += 1;
            else
                freqMap[i] = 1;
        }

        int ans = 0;
        auto itr = freqMap.begin();
        while (itr != freqMap.end()) {
            if (itr->second > 1) {
                ans += itr->second;
            }
            itr++;
        }

        return ans;
    }
};