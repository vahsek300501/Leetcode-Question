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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        for(ListNode * tmp = head; tmp!=NULL;tmp = tmp->next){
            n++;
        }
        int ePos = n-k+1;
        ListNode * s = NULL;
        ListNode * e = NULL;
        int i = 1;
        for(ListNode * tmp = head;tmp!=NULL;tmp = tmp->next) {
            if(i == k)
                s = tmp;
            if(i == ePos) {
                e = tmp;
            }
            i++;
        }
        
        int tmpData = s->val;
        s->val = e->val;
        e->val = tmpData;
        return head;
    }
};