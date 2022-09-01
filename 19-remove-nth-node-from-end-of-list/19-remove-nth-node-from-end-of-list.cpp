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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = nullptr;
        ListNode *next = head;

        while (next != nullptr) {
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
        }
        head = curr;
        return head;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head->next == nullptr || n == 0)
            return nullptr;
        head = reverseList(head);
        if (n == 1) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = nullptr;
            head = reverseList(head);
            return head;
        }
        int count = 2;
        ListNode *prevPtr = head;
        for (ListNode *tmp = head->next; tmp != nullptr; tmp = tmp->next) {
            if (count == n) {
                prevPtr->next = tmp->next;
                tmp->next = nullptr;
                break;
            }
            prevPtr = prevPtr->next;
            count++;
        }
        head = reverseList(head);
        return head;
    }
};