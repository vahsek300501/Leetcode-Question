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
    void sumEvenGrandparentUtil(TreeNode * root, vector<int>& ans) {
        if(root == nullptr)
            return;
        if(root->val%2 == 0){
            if(root->left!= nullptr && root->left->left != nullptr)
                ans.push_back(root->left->left->val);
            if(root->left!= nullptr && root->left->right != nullptr)
                ans.push_back(root->left->right->val);
            if(root->right!= nullptr && root->right->left != nullptr)
                ans.push_back(root->right->left->val);
            if(root->right!= nullptr && root->right->right != nullptr)
                ans.push_back(root->right->right->val);
        }
        sumEvenGrandparentUtil(root->left,ans);
        sumEvenGrandparentUtil(root->right,ans);
    }

    int sumEvenGrandparent(TreeNode *root) {
        vector<int> ans;
        sumEvenGrandparentUtil(root,ans);
        int sum = 0;
        for(int i=0;i<ans.size();i++) {
            sum+=ans.at(i);
        }
        return sum;
    }
};