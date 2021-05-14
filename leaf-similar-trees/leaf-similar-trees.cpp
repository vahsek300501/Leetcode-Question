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
    void inorderTraversal(TreeNode * root,vector<int>& arr) {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
            arr.push_back(root->val);
        inorderTraversal(root->left,arr);
        inorderTraversal(root->right,arr);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;

        vector<int> trav1;
        vector<int> trav2;
        inorderTraversal(root1,trav1);
        inorderTraversal(root2,trav2);

        if (trav1.size() != trav2.size())
            return false;

        for (int i = 0; i < trav1.size(); i++) {
            if (trav1.at(i) != trav2.at(i))
                return false;
        }
        return true;
    }
};