/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node *> listPointers;
        Node * tmp = head;
        
        while(true) {
            if(listPointers.empty() && tmp == NULL)
                break;
            if(listPointers.empty() && tmp->next == NULL &&tmp->child == NULL ){
                break;
            }
            if(tmp->next == NULL && !listPointers.empty()){
                Node * tmp2 = listPointers.top();
                listPointers.pop();
                if(tmp2 == NULL)
                    continue;
                tmp->next = tmp2;
                tmp2->prev = tmp;
            }
            if(tmp->child!=NULL){
                Node * tmp2 = tmp->next;
                Node * tmp3 = tmp->child;
                if(tmp2!=NULL)
                    tmp2->prev = NULL;
                tmp->next = NULL;
                tmp->child = NULL;
                tmp->next = tmp3;
                tmp3->prev = tmp;
                listPointers.push(tmp2);
            }
            tmp = tmp->next;
        }
        return head;    
    }
};