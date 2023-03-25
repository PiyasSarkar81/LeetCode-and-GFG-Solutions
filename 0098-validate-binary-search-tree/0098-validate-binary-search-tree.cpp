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
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return validate(root,pre);
    }
    bool validate(TreeNode* node, TreeNode* &pre){
        if(node==NULL) return true;
        if(!validate(node->left,pre)) return false;
        if(pre!=NULL && pre->val >= node->val) return false;
        pre = node;
        return validate(node->right,pre);
    }
};