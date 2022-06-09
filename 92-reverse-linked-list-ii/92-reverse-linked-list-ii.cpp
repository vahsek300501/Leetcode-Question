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
    ListNode *reverseListIterative(ListNode *head) {
        ListNode *prevPtr = nullptr;
        ListNode *currPtr = nullptr;
        ListNode *nextPtr = head;

        while (nextPtr != nullptr) {
            currPtr = nextPtr;
            nextPtr = nextPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
        }
        return currPtr;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *startLst = nullptr;
        ListNode *endLst = nullptr;
        ListNode *tmp = head;
        int cntPos = 1;
        while (tmp!=nullptr) {
            if (cntPos == left)
                break;
            startLst = tmp;
            tmp = tmp->next;
            cntPos++;
        }
        while (tmp!=nullptr) {
            if (cntPos == right) {
                endLst = tmp->next;
                tmp->next = nullptr;
                break;
            }
            tmp = tmp->next;
            cntPos++;
        }

        ListNode *reverseListStart = startLst == nullptr ? head : startLst->next;
        if (startLst != nullptr)
            startLst->next = nullptr;
        reverseListStart = reverseListIterative(reverseListStart);
        ListNode *reversedListEnd = reverseListStart;
        while (reversedListEnd->next != nullptr)
            reversedListEnd = reversedListEnd->next;

        reversedListEnd->next = endLst;
        if (startLst == nullptr)
            return reverseListStart;
        startLst->next = reverseListStart;
        return head;
    }
};