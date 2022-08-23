#include <bits/stdc++.h> 
using namespace std; 
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
    
    struct Node{
        int data;
        Node* next;
        Node * prev;
        Node() {
            next = NULL;
            prev = NULL;
        }
    };
    Node * first = NULL;
    Node * last = NULL;
    
    void push(int p_data) {
        Node * newNode = new Node();
        newNode->data= p_data;
        
        if(first == NULL && last == NULL) {
            first = newNode;
            last = newNode;
            return;
        }
        
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    
    bool isPalindrome(ListNode* head) {
        for(ListNode * tmp = head;tmp!=NULL;tmp = tmp->next) {
            push(tmp->val);
        }
        
        ListNode* tmpLstNode = head;
        bool found = false;
        for(Node * tmp = last;tmp!=NULL;tmp = tmp->prev) {
            if(tmp->data == tmpLstNode->val) {
                tmpLstNode = tmpLstNode->next;
                continue;
            }
            else{
                found = true;
            }
        }
        
        if(found == true) {
            return false;
        }
        return true;
    
    }
};