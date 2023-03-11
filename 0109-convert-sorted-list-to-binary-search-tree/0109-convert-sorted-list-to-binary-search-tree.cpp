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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructBST(vector<int>& v,int l,int r){
        if(l>r) return NULL;
        
        int m = l + (r-l)/2;
        int rootVal = v[m];
        TreeNode* root = new TreeNode(rootVal);
        root -> left = constructBST(v,l,m-1);
        root -> right = constructBST(v,m+1,r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head -> next;
        }
        return constructBST(v,0,v.size()-1);
    }
};