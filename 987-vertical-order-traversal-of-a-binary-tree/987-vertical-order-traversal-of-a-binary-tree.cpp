/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeTraversal {
public:
    int nodeVal;
    int x;
    int y;
};

bool compare(NodeTraversal o1, NodeTraversal o2) {
    if (o1.x < o2.x)
        return true;
    if (o1.x == o2.x && o1.y < o2.y)
        return true;
    if (o1.x == o2.x && o1.y == o2.y && o1.nodeVal < o2.nodeVal)
        return true;
    return false;
}

class Solution {
public:
    void inorder(TreeNode *root, vector<NodeTraversal> &nodes, int x, int y) {
        if (root == nullptr)
            return;
        inorder(root->left, nodes, x - 1, y + 1);
        NodeTraversal tmpNode{};
        tmpNode.nodeVal = root->val;
        tmpNode.x = x;
        tmpNode.y = y;
        nodes.push_back(tmpNode);
        inorder(root->right, nodes, x + 1, y + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        vector<NodeTraversal> nodes;
        inorder(root, nodes, 0, 0);
        sort(nodes.begin(), nodes.end(), compare);
        int distinctArrays = nodes.at(nodes.size() - 1).x - nodes.at(0).x + 1;
        for (int i = 0; i < distinctArrays; i++) {
            vector<int> tmp;
            ans.push_back(tmp);
        }
        int tmpIncrease = 0 - nodes.at(0).x;
        for (int i = 0; i < nodes.size(); i++) {
            NodeTraversal tmpNode = nodes.at(i);
            ans.at(tmpNode.x + tmpIncrease).push_back(tmpNode.nodeVal);
        }
        return ans;
    }
};