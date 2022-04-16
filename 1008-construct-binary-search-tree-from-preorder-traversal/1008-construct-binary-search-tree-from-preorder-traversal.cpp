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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        if ((int) preorder.size() <= 0)
            return nullptr;
        auto *root = new TreeNode(preorder.at(0));
        vector<int> leftSubtree;
        vector<int> rightSubtree;
        int i = 1;
        while (i < preorder.size() && preorder[i] < root->val) {
            leftSubtree.push_back(preorder[i]);
            i++;
        }
        while (i < preorder.size() && preorder[i] > root->val) {
            rightSubtree.push_back(preorder[i]);
            i++;
        }
        root->left = bstFromPreorder(leftSubtree);
        root->right = bstFromPreorder(rightSubtree);
        return root;
    }
};