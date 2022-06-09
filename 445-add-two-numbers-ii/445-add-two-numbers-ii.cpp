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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        l1 = reverseListIterative(l1);
        l2 = reverseListIterative(l2);
        ListNode *ansStart = nullptr;
        ListNode *ansEnd = nullptr;

        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;

        int carry = 0;
        while (tmp1 != nullptr && tmp2 != nullptr) {
            int num = tmp1->val + tmp2->val + carry;
            carry = num / 10;
            num = num % 10;
            auto *newNode = new ListNode(num);
            if (ansStart == nullptr) {
                ansStart = newNode;
                ansEnd = newNode;
            } else {
                if (ansEnd != nullptr) {
                    ansEnd->next = newNode;
                    ansEnd = newNode;
                }
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        if (tmp1 == nullptr && tmp2 != nullptr) {
            while (tmp2 != nullptr) {
                int num = tmp2->val + carry;
                carry = num / 10;
                num = num % 10;
                auto *newNode = new ListNode(num);
                if (ansStart == nullptr) {
                    ansStart = newNode;
                    ansEnd = newNode;
                } else {
                    if (ansEnd != nullptr) {
                        ansEnd->next = newNode;
                        ansEnd = newNode;
                    }
                }
                tmp2 = tmp2->next;
            }
        }

        if (tmp1 != nullptr && tmp2 == nullptr) {
            while (tmp1 != nullptr) {
                int num = tmp1->val + carry;
                carry = num / 10;
                num = num % 10;
                auto *newNode = new ListNode(num);
                if (ansStart == nullptr) {
                    ansStart = newNode;
                    ansEnd = newNode;
                } else {
                    if (ansEnd != nullptr) {
                        ansEnd->next = newNode;
                        ansEnd = newNode;
                    }
                }
                tmp1 = tmp1->next;
            }
        }

        if (carry != 0) {
            auto *newNode = new ListNode(carry);
            ansEnd->next = newNode;
            ansEnd = newNode;
        }
        ansStart = reverseListIterative(ansStart);
        return ansStart;
    }
};