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
    ListNode* headNode; 
public:
    Solution(ListNode* head) {
        headNode = head;
    }
    
    int getRandom() {
        int l =0;
        vector<int> v;
        ListNode* temp = headNode;
        while(temp){
            l++;
            v.push_back(temp->val);
            temp = temp -> next;
        }
        return v[rand()%l];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */