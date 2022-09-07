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
    void tree2strUtil(TreeNode * root,string &ans) {
        if(root == nullptr)
            return;
        ans += to_string(root->val);
        if(root->left != nullptr) {
            ans += '(';
            tree2strUtil(root->left,ans);    
            ans += ')';
        }
        if(root->right != nullptr) {
            if(root->left == nullptr) {
                ans += "()";
            }
            ans += '(';
            tree2strUtil(root->right,ans);
            ans += ')';   
        }
    }
    string tree2str(TreeNode* root) {
        string ans;
        tree2strUtil(root,ans);
        return ans;
    }
};