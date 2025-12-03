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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int c = 0;
        while(l1 != nullptr && l2 != nullptr){
            int val = l1->val + l2->val + c;
            c = val/10;
            temp -> next = new ListNode(val%10);
            temp = temp -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != nullptr){
            int val = l1-> val + c;
            c = val/10;
            temp -> next = new ListNode(val%10);
            temp = temp -> next;
            l1 = l1 -> next;
        }
        while(l2 != nullptr){
            int val = l2-> val + c;
            c = val/10;
            temp -> next = new ListNode(val%10);
            temp = temp -> next;
            l2 = l2 -> next;
        }
        while(c){
            temp -> next = new ListNode(c%10);
            temp = temp -> next;
            c /= 10;
        }

        return head -> next;
    }
};