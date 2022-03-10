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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(new TreeNode(INT_MIN));

        while (!q.empty()) {
            if (q.size() == 1 && q.front()->val == INT_MIN)
                break;
            vector<int> level;
            while (true) {
                if (q.front()->val == INT_MIN) {
                    TreeNode *tmp = q.front();
                    q.pop();
                    q.push(tmp);
                    ans.push_back(level);
                    break;
                } else {
                    level.push_back(q.front()->val);
                    TreeNode *tmp = q.front();
                    q.pop();
                    if (tmp->left != nullptr)
                        q.push(tmp->left);
                    if (tmp->right != nullptr)
                        q.push(tmp->right);
                }
            }
        }
        return ans;
    }
};