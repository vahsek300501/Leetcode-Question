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
    ListNode *getMiddleElement(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr && slow != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *deleteMiddle(ListNode *head) {
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
            return nullptr;
        ListNode *midPtr = getMiddleElement(head);
        for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (tmp->next == midPtr) {
                tmp->next = tmp->next->next;
                midPtr->next = nullptr;
                break;
            }
        }
        return head;
    }
};