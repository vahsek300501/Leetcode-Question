/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void addNodesAtDistanceK(TreeNode *root, int cntDistance, vector<int> &ans) {
        if (root == nullptr)
            return;
        if (cntDistance == 0) {
            ans.push_back(root->val);
            return;
        }
        addNodesAtDistanceK(root->left, cntDistance - 1, ans);
        addNodesAtDistanceK(root->right, cntDistance - 1, ans);
    }

    bool getPathFromRoot(TreeNode *root, TreeNode *target, stack<pair<TreeNode *, char>> &path) {
        if (root == nullptr)
            return false;
        if (root == target) {
            return true;
        }
        path.push(make_pair(root, 'R'));
        bool foundLeft = getPathFromRoot(root->left, target, path);
        if (foundLeft)
            return true;
        path.pop();
        path.push(make_pair(root, 'L'));
        bool foundRight = getPathFromRoot(root->right, target, path);
        if (foundRight)
            return true;
        path.pop();
        return false;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        if (k == 0) {
            ans.push_back(target->val);
            return ans;
        }
        addNodesAtDistanceK(target, k, ans);
        stack<pair<TreeNode *, char>> pathStack;
        getPathFromRoot(root, target, pathStack);
        int cntK = k - 1;
        while (!pathStack.empty()) {
            if (cntK < 0)
                break;
            if (cntK == 0) {
                ans.push_back(pathStack.top().first->val);
                break;
            }
            pair<TreeNode *, char> tmp = pathStack.top();
            pathStack.pop();
            if (tmp.second == 'R') {
                addNodesAtDistanceK(tmp.first->right, cntK-1, ans);
            } else {
                addNodesAtDistanceK(tmp.first->left, cntK-1, ans);
            }
            cntK--;
        }
        return ans;
    }
};