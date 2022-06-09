// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverseList(Node *head) {
        Node *prevPtr = nullptr;
        Node *currPtr = nullptr;
        Node *nextPtr = head;

        while (nextPtr != nullptr) {
            currPtr = nextPtr;
            nextPtr = nextPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
        }
        return currPtr;
    }
    Node *compute(Node *head) {
        if(head == nullptr)
            return head;
        head = reverseList(head);
        int nextMax = INT_MIN;
        Node *tmp = head;
        bool deleteFirstNode = false;
        while (true) {
            if(tmp == nullptr)
                break;
            if (tmp->next == nullptr) {
                if (tmp->data < nextMax)
                    deleteFirstNode = true;
                break;
            }
            if (tmp->data >= nextMax) {
                nextMax = max(nextMax, tmp->data);
                tmp = tmp->next;
            } else {
                tmp->data = tmp->next->data;
                tmp->next = tmp->next->next;
            }
        }
        head = reverseList(head);
        if (deleteFirstNode) {
            head = head->next;
        }
        return head;
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends