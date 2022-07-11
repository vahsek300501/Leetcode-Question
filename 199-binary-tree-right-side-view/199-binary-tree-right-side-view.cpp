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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode *> traversalQueue;
        TreeNode *delim = new TreeNode(INT_MIN);
        traversalQueue.push(root);
        traversalQueue.push(delim);
        while (true) {
            TreeNode *top = traversalQueue.front();
            traversalQueue.pop();
            if (top->val == INT_MIN) {
                if (traversalQueue.empty())
                    break;
                else {
                    traversalQueue.push(top);
                    continue;
                }
            }
            if (traversalQueue.front()->val == INT_MIN) {
                ans.push_back(top->val);
            }
            if (top->left != nullptr)
                traversalQueue.push(top->left);
            if (top->right != nullptr)
                traversalQueue.push(top->right);
        }
        return ans;
    }
};