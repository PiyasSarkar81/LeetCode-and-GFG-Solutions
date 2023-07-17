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
      stack<int> s1,s2;
      while(l1!=NULL){
          s1.push(l1->val);
          l1 = l1-> next;
      }
      while(l2!=NULL){
          s2.push(l2->val);
          l2= l2 -> next;
      }
      int totalsum = 0, carry = 0;
      ListNode* ans = new ListNode();
      while(!s1.empty() || !s2.empty()){
          if(!s1.empty()){
              totalsum += s1.top();
              s1.pop();
          }
          if(!s2.empty()){
              totalsum += s2.top();
              s2.pop();
          }

          ans -> val = totalsum%10;
          carry = totalsum /10;
          ListNode* newNode = new ListNode(carry);
          newNode -> next = ans;
          ans = newNode;
          totalsum = carry;
      }
      return carry == 0? ans -> next : ans;
    }
};