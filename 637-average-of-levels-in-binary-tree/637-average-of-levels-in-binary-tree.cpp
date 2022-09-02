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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode *> traversalQueue;
        traversalQueue.push(root);
        traversalQueue.push(nullptr);
        double cntAns = 0;
        int levelCount = 0;
        while (true) {
            if (traversalQueue.size() == 1)
                break;
            if (traversalQueue.front() == nullptr) {
                traversalQueue.pop();
                traversalQueue.push(nullptr);
                ans.push_back(cntAns / (double) levelCount);
                cntAns = 0;
                levelCount = 0;
                continue;
            }
            TreeNode *top = traversalQueue.front();
            traversalQueue.pop();
            cntAns += (double) top->val;
            levelCount++;
            if (top->left != nullptr) {
                traversalQueue.push(top->left);
            }
            if (top->right != nullptr) {
                traversalQueue.push(top->right);
            }
        }
        ans.push_back(cntAns/levelCount);
        return ans;
    }
};