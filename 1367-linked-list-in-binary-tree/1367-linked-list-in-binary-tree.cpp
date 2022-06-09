/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPathUtil(ListNode *head, TreeNode *root, bool isPreviousFound) {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
        bool foundLeft = false;
        bool foundRight = false;
        if (isPreviousFound) {
            if (head->val == root->val) {
                foundLeft = isSubPathUtil(head->next, root->left, true);
                foundRight = isSubPathUtil(head->next, root->right, true);
            }
            if (foundLeft || foundRight)
                return true;
            return false;
        } else {
            if (head->val == root->val) {
                foundLeft = isSubPathUtil(head->next, root->left, true);
                foundRight = isSubPathUtil(head->next, root->right, true);
            }
            if (foundLeft || foundRight) {
                return true;
            } else {
                return isSubPathUtil(head, root->left, false) || isSubPathUtil(head, root->right, false);
            }
        }
        return false;
    }

    bool isSubPath(ListNode *head, TreeNode *root) {
        return isSubPathUtil(head, root, false);
    }
};