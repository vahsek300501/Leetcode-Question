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
    int getMaxHeight(TreeNode * root,int crntHeight) {
        if(root == nullptr)
            return crntHeight;
        return max(getMaxHeight(root->left,crntHeight+1), getMaxHeight(root->right,crntHeight+1));
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxHeight = getMaxHeight(root,0);
        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(1,root));
        vector<int> ans;
        while(!q.empty()) {
            pair<int,TreeNode*> tmp = q.front();
            q.pop();
            if(tmp.first == maxHeight){
                ans.push_back(tmp.second->val);
            } 
            if(tmp.second->left != nullptr){
                q.push(make_pair(tmp.first+1,tmp.second->left));
            }
            if(tmp.second->right!= nullptr) {
                q.push(make_pair(tmp.first+1,tmp.second->right));
            }
        }
        return ans.at(0);
    }
};