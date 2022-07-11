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
    ListNode *reverseKGroupUtil(ListNode *head, int k, int listLen, int cntLen) {
        if (k == 0)
            return head;
        if (head == nullptr || head->next == nullptr)
            return head;
        if (listLen - cntLen < k)
            return head;
        ListNode *prev = nullptr;
        ListNode *curr = nullptr;
        ListNode *next = head;
        int counter = 0;
        while (next != nullptr && counter < k) {
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
            counter++;
        }
        ListNode *nextKReversed = reverseKGroupUtil(next, k, listLen, cntLen + k);
        head->next = nextKReversed;
        return curr;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        int listLen = 0;
        for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
            listLen++;
        }
        return reverseKGroupUtil(head, k, listLen, 0);
    }
};