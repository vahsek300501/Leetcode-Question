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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        stack<TreeNode *> leftToRight;
        stack<TreeNode *> rightToLeft;

        leftToRight.push(root);
        while (true) {
            if (leftToRight.empty() && rightToLeft.empty())
                break;
            vector<int> level;
            if (!leftToRight.empty()) {
                while (!leftToRight.empty()) {
                    TreeNode *topNode = leftToRight.top();
                    leftToRight.pop();
                    level.push_back(topNode->val);
                    if (topNode->left != nullptr)
                        rightToLeft.push(topNode->left);
                    if (topNode->right != nullptr)
                        rightToLeft.push(topNode->right);
                }
            } else {
                while (!rightToLeft.empty()) {
                    TreeNode *topNode = rightToLeft.top();
                    rightToLeft.pop();
                    level.push_back(topNode->val);
                    if (topNode->right != nullptr)
                        leftToRight.push(topNode->right);
                    if (topNode->left != nullptr) {
                        leftToRight.push(topNode->left);
                    }
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};