//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int resolveToRootParentUtil(vector<int> &parent, int cntInd) {
        if (parent[cntInd] == cntInd)
            return cntInd;
        int tmpParent = resolveToRootParentUtil(parent, parent[cntInd]);
        parent[cntInd] = tmpParent;
        return tmpParent;
    }

    void resolveToRootParent(vector<int> &parentArr) {
        for (int i = 0; i < parentArr.size(); i++) {
            int tmp = parentArr[i];
            if (tmp == parentArr[tmp])
                continue;
            else
                resolveToRootParentUtil(parentArr, i);
        }
    }

    int removeStones(vector<vector<int>> &stones) {
        int n = (int) stones.size();
        UnionFindAlgorithm stoneUnion(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    stoneUnion.findUnion(i, j);
                }
            }
        }

        vector<int> parentArr = stoneUnion.getParentArr();
        resolveToRootParent(parentArr);
        set<int> uniqueParents;
        for (int parent : parentArr) {
            uniqueParents.insert(parent);
        }
        return n - ((int) uniqueParents.size());
    }
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        return removeStones(stones);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends