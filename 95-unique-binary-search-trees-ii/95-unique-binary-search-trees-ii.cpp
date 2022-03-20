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
    vector<TreeNode *> generateTreesUtil(int s, int e) {
        vector<TreeNode *> ans;
        if (s > e)
            return ans;

        for (int i = s; i <= e; i++) {
            vector<TreeNode *> leftSubtrees = generateTreesUtil(s, i - 1);
            vector<TreeNode *> rightSubtrees = generateTreesUtil(i + 1, e);

            if (!leftSubtrees.empty() && !rightSubtrees.empty()) {
                for (auto &leftSubtree : leftSubtrees) {
                    for (auto &rightSubtree : rightSubtrees) {
                        auto *root = new TreeNode(i);
                        root->left = leftSubtree;
                        root->right = rightSubtree;
                        ans.push_back(root);
                    }
                }
            }
            if (leftSubtrees.empty() && !rightSubtrees.empty()) {
                for (auto &rightSubtree : rightSubtrees) {
                    auto *root = new TreeNode(i);
                    root->right = rightSubtree;
                    ans.push_back(root);
                }
            }
            if (rightSubtrees.empty() && !leftSubtrees.empty()) {
                for (auto &leftSubtree : leftSubtrees) {
                    auto *root = new TreeNode(i);
                    root->left = leftSubtree;
                    ans.push_back(root);
                }
            }
            if (rightSubtrees.empty() && leftSubtrees.empty()) {
                auto *root = new TreeNode(i);
                ans.push_back(root);
            }
        }
        return ans;
    }

    vector<TreeNode *> generateTrees(int n) {
        return generateTreesUtil(1, n);
    }
};