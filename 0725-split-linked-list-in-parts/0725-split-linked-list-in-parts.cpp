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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt =0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp= temp->next;
        }
        int l = cnt/k;
        int ext = cnt%k;
        cout<<l<<" "<<ext;
        vector<ListNode*>ans;
        temp = head;
        ListNode* last;
        for(int i=0;i<ext;i++){
            ListNode* newHead=temp;
            for(int j =0;j<l;j++){
                if(temp)temp = temp->next;
            }
            last = temp;
            if(temp)temp = temp->next;
            if(last)last->next=NULL;
            ans.push_back(newHead);
        }
        for(int i=0;i<k-ext;i++){
            ListNode* newHead=temp;
            for(int j =0;j<l-1;j++){
                if(temp)temp = temp->next;
            }
            last = temp;
            if(temp)temp = temp->next;
            if(last)last->next=NULL;
            ans.push_back(newHead);
        }
        return ans;
    }
};