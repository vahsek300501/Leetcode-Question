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
    int pairSum(ListNode *head) {
        vector<int> listToArray;
        for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next)
            listToArray.push_back(tmp->val);

        int maxVal = INT_MIN;

        int i = 0, j = (int) listToArray.size() - 1;
        while (i < j) {
            if (listToArray.at(i) + listToArray.at(j) > maxVal)
                maxVal = listToArray.at(i) + listToArray.at(j);
            i++;
            j--;
        }
        return maxVal;
    }
};