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
class Solution {
public:
    pair<int, int> longestZigZagPathUtil(TreeNode *root, vector<int> &longestZigZagPathCntNode) {
        if (root == nullptr)
            return make_pair(0, 0);
        pair<int, int> leftSubtree = longestZigZagPathUtil(root->left, longestZigZagPathCntNode);
        pair<int, int> rightSubtree = longestZigZagPathUtil(root->right, longestZigZagPathCntNode);
        int leftZigZagPath = leftSubtree.second;
        int rightZigZagPath = rightSubtree.first;
        if (root->left != nullptr)
            leftZigZagPath++;
        if (root->right != nullptr)
            rightZigZagPath++;
        longestZigZagPathCntNode.push_back(max(leftZigZagPath, rightZigZagPath));
        return make_pair(leftZigZagPath, rightZigZagPath);
    }

    int longestZigZag(TreeNode *root) {
        vector<int> longestZigZagPathCntNode;
        longestZigZagPathUtil(root, longestZigZagPathCntNode);
        int maxZigZagPathLen = INT_MIN;
        for (auto pathLen: longestZigZagPathCntNode)
            maxZigZagPathLen = max(maxZigZagPathLen, pathLen);
        return maxZigZagPathLen;
    }
};