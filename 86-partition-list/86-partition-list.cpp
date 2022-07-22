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
    ListNode *partition(ListNode *head, int x) {
        ListNode * beforeHead = NULL;
        ListNode * beforeTail = NULL;
        ListNode * afterHead = NULL;
        ListNode * afterTail = NULL;

        for(ListNode * tmp = head;tmp!=NULL; tmp = tmp->next) {
            ListNode * newNode = new ListNode(tmp->val);
            if(tmp->val < x) {
                if(beforeHead == NULL){
                    beforeHead = newNode;
                    beforeTail = newNode;
                    continue;
                }
                beforeTail->next = newNode;
                beforeTail = newNode;
            }
            else {
                if(afterHead == NULL){
                    afterHead = newNode;
                    afterTail = newNode;
                    continue;
                }
                afterTail->next = newNode;
                afterTail = newNode;
            }
        }
        if(beforeHead != NULL && afterHead != NULL)
            beforeTail -> next = afterHead;
        if(beforeHead == NULL && afterHead!= NULL)
            return afterHead;
        return beforeHead;
    }
};