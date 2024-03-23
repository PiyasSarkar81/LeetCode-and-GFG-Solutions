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
    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;

        ListNode * slow=head;
        ListNode * fast=head;
        
        stack<int> st;
              
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode * temp=slow->next;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }

        slow->next=NULL;

        temp=head;
       

        while(!st.empty()){
             ListNode * nxt=temp->next;
            temp->next=new ListNode(st.top());st.pop();
            temp->next->next = nxt;
            temp=nxt;
        }
    }
};