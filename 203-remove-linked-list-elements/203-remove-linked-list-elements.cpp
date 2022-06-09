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
    ListNode *removeElements(ListNode *head, int val) {
        if(head == nullptr)
            return head;
        while (head != nullptr && head->val == val) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = nullptr;
            delete tmp;
        }
        ListNode *ans = head;
        while (head != nullptr && head->next != nullptr) {
            if (head->next->val == val) {
                ListNode *tmp = head->next;
                head->next = head->next->next;
                tmp->next = nullptr;
                delete tmp;
            } else {
                head = head->next;
            }
        }
        return ans;
    }
};