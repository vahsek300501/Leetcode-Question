/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *connect(Node *root) {
        if(root == nullptr)
            return nullptr;
        queue<Node *> traversalQueue;
        traversalQueue.push(root);
        Node *endingNode = new Node(INT_MIN);
        traversalQueue.push(endingNode);

        while (true) {
            if (traversalQueue.size() == 1 && traversalQueue.front()->val == INT_MIN)
                break;
            Node *frontNode = traversalQueue.front();
            traversalQueue.pop();
            if (frontNode->val == INT_MIN) {
                traversalQueue.push(frontNode);
                continue;
            }
            if (traversalQueue.front()->val == INT_MIN) {
                frontNode->next = nullptr;
            } else {
                frontNode->next = traversalQueue.front();
            }
            if (frontNode->left != nullptr)
                traversalQueue.push(frontNode->left);
            if (frontNode->right != nullptr)
                traversalQueue.push(frontNode->right);
        }
        traversalQueue.pop();
        delete endingNode;
        return root;
    }
};