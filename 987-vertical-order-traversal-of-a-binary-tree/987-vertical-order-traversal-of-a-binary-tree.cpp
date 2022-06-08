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
    void inorderTraversal(TreeNode *root, vector<pair<int, pair<int, int>>> &ans, int cntX, int cntY) {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, ans, cntX + 1, cntY - 1);
        pair<int, pair<int, int>> tmp;
        tmp.first = root->val;
        tmp.second.first = cntX;
        tmp.second.second = cntY;
        ans.push_back(tmp);
        inorderTraversal(root->right, ans, cntX + 1, cntY + 1);
    }

    static bool comparator(pair<int, pair<int, int>> &o1, pair<int, pair<int, int>> &o2) {
        if (o1.second.second < o2.second.second)
            return true;
        if (o1.second.second == o2.second.second && o1.second.first < o2.second.first)
            return true;
        if (o1.second.second == o2.second.second && o1.second.first == o2.second.first && o1.first < o2.first)
            return true;
        return false;
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> finalAns;
        if (root == nullptr)
            return finalAns;
        vector<pair<int, pair<int, int>>> ans;
        inorderTraversal(root, ans, 0, 0);
        sort(ans.begin(), ans.end(), comparator);
        for (auto &an : ans) {
            cout << an.first << " ";
        }
        int j = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (i == 0) {
                vector<int> tmp;
                tmp.push_back(ans.at(i).first);
                finalAns.push_back(tmp);
                continue;
            }
            if (ans[i].second.second == ans.at(i - 1).second.second) {
                finalAns[j].push_back(ans[i].first);
            } else {
                vector<int> tmp;
                tmp.push_back(ans.at(i).first);
                finalAns.push_back(tmp);
                j++;
            }
        }
        return finalAns;
    }
};