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
        ListNode *middleNode(ListNode *head) {
        int n = 0;
        for (ListNode *tmp = head; tmp != NULL; tmp = tmp->next) {
            n++;
        }
        int midIndex = -1;
        if(n%2 != 0)
            midIndex = (n/2);
        else
            midIndex = (n/2);
        cout<<midIndex<<endl;
        int i = 0;
        ListNode * tmpNode = NULL;
        for(ListNode * tmp = head;tmp!=NULL;tmp = tmp->next) {
            if(i == midIndex)
                tmpNode = tmp;
            i++;
        }
        return tmpNode;
    }
};