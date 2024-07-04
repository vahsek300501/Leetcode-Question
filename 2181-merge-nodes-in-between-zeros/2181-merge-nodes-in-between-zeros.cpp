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
    ListNode *mergeNodes(ListNode *head) {
        ListNode *finalAnsLstHead = nullptr;
        ListNode *finalAnsLstTail = nullptr;
        ListNode *tmp = head;
        while (tmp != nullptr && tmp->next != nullptr) {
            if (tmp->val == 0) {
                tmp = tmp->next;
                int newNodeVal = 0;
                while (tmp->val != 0) {
                    newNodeVal += tmp->val;
                    tmp = tmp->next;
                }
                auto *newNode = new ListNode(newNodeVal);
                if (finalAnsLstHead == nullptr) {
                    finalAnsLstHead = newNode;
                    finalAnsLstTail = newNode;
                } else {
                    finalAnsLstTail->next = newNode;
                    finalAnsLstTail = newNode;
                }
            }
        }
        return finalAnsLstHead;
    }
};