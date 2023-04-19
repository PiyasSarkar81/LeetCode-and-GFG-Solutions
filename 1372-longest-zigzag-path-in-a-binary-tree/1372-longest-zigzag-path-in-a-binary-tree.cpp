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
    int length(TreeNode* node,bool right,int cnt){
        if(node==NULL) return cnt;
        return (right)?max(length(node->left,false,cnt+1),length(node->right,true,0)):max(length(node->right,true,cnt+1),length(node->left,false,0));
        
    }
    int longestZigZag(TreeNode* root) {
        return max(length(root->right,true,0),length(root->left,false,0));
    }
};