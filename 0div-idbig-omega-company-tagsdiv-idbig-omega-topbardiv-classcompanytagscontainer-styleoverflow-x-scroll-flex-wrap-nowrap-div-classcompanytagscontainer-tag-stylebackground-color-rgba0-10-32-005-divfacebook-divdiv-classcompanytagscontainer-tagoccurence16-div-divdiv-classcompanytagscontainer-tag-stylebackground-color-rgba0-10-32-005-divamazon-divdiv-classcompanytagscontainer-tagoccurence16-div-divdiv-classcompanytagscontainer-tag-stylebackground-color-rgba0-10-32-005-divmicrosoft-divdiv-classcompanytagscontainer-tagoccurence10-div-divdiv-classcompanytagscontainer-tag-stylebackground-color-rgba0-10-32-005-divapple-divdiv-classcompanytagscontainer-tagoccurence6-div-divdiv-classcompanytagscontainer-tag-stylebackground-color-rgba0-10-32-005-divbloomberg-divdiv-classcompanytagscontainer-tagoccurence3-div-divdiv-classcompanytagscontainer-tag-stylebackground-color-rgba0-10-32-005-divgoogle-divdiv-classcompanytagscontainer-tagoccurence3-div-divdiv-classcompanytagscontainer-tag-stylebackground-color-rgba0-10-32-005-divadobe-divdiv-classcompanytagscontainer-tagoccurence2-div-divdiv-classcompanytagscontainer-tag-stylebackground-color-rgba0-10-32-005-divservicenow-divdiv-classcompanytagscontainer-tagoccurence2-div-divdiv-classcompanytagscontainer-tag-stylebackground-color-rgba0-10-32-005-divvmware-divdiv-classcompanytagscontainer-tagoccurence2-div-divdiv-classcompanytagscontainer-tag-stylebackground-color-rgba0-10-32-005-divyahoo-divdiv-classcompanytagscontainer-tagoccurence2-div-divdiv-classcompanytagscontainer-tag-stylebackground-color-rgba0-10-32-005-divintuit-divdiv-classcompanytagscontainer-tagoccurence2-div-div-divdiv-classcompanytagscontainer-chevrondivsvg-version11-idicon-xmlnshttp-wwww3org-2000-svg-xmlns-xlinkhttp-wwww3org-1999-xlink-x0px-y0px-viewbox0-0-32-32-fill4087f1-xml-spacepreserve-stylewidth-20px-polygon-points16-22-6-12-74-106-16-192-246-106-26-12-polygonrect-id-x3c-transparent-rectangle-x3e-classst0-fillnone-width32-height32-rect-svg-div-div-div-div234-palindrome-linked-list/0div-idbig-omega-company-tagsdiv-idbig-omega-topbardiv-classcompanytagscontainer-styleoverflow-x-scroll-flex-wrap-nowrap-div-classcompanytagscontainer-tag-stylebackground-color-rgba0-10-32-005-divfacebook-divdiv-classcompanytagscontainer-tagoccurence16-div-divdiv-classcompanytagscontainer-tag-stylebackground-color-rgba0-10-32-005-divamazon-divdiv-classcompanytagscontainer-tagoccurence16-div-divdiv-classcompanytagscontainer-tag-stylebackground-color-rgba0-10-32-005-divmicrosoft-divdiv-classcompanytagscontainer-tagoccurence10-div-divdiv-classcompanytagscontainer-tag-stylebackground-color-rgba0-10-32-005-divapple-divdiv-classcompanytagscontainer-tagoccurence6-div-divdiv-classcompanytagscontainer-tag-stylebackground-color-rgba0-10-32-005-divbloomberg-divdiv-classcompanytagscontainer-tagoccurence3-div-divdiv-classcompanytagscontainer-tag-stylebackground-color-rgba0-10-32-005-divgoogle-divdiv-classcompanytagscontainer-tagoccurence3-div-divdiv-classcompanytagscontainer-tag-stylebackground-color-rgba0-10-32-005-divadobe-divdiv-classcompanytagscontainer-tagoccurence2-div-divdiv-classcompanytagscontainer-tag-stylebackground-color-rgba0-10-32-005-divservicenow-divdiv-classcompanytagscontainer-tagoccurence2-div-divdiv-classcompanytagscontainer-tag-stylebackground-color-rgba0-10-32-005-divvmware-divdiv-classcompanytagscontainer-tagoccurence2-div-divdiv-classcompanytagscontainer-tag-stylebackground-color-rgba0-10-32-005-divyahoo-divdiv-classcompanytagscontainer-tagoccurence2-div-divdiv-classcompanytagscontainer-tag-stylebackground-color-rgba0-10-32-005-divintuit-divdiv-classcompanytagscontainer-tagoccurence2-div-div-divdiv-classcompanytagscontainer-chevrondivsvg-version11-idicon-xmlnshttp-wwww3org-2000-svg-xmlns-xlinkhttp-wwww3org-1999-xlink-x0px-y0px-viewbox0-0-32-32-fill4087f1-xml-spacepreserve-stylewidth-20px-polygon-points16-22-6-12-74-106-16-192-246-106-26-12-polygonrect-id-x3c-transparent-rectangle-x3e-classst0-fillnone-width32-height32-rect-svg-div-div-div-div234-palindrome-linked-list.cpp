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

     ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL,*curr=head,*n=head;
        while(n){
            n = n->next;
            curr->next = pre;
            pre=curr;
            curr=n;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode*fast=head,*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        fast=head;
        while(slow){
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast = fast -> next;
        }
        return true;
    }
};