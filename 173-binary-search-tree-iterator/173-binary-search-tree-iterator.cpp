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
class BSTIterator {
private:
    vector<int> traversal;
    int i;

    void traverseBST(TreeNode *root) {
        if (root == nullptr)
            return;
        traverseBST(root->left);
        traversal.push_back(root->val);
        traverseBST(root->right);
    }

public:
    BSTIterator(TreeNode *root) {
        traverseBST(root);
        i = 0;
    }

    int next() {
        if (i < traversal.size()) {
            int tmp = traversal.at(i);
            i++;
            return tmp;
        }
        return INT_MIN;
    }

    bool hasNext() {
        if (i < traversal.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */