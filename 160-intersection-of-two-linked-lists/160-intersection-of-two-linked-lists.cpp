/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        for(ListNode * tmp = headA;tmp!=NULL;tmp = tmp->next)
            lengthA++;
        for(ListNode * tmp = headB;tmp!=NULL;tmp = tmp->next)
            lengthB++;
        
        ListNode * longer = NULL;
        ListNode * shorter = NULL;
        int d = 0;
        if(lengthA >= lengthB) {
            d = lengthA - lengthB;
            longer = headA;
            shorter = headB;
        }
        else {
            d = lengthB - lengthA;
            longer = headB;
            shorter = headA;
        }
        ListNode * ans = NULL;
        while(longer !=NULL && shorter!=NULL) {
            if(d!=0) {
                longer = longer->next;
                d--;
                continue;
            }
            if(longer == shorter) {
                ans = longer;
                break;
            }
            longer = longer->next;
            shorter = shorter->next;
        }
        return ans;
    }
};