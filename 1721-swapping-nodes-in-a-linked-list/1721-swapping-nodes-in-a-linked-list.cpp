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
        ListNode* temp1 = head;
        while(--k) {
            temp1 = temp1 -> next;
        } 
        int tempVal = temp1 -> val;
        ListNode* temp2 = head;
        ListNode* temp3 = temp1 -> next;
        while(temp3 != NULL) {
            temp3 = temp3 -> next;
            temp2 = temp2 -> next;
        }
        temp1 -> val = temp2 -> val;
        temp2 -> val = tempVal; 
        return head;
    }
};