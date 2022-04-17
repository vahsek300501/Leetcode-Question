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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> arr;
        for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
            arr.push_back(tmp->val);
        }
        vector<int> ans;
        stack<int> nextGreaterStack;
        ans.reserve(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(0);
        }
        for (int i = (int) arr.size() - 1; i >= 0; i--) {
            while (!nextGreaterStack.empty() && nextGreaterStack.top() <= arr.at(i))
                nextGreaterStack.pop();
            if (nextGreaterStack.empty()) {
                ans.at(i) = 0;
                nextGreaterStack.push(arr.at(i));
            } else {
                ans.at(i) = nextGreaterStack.top();
                nextGreaterStack.push(arr.at(i));
            }
        }
        return ans;
    }
};