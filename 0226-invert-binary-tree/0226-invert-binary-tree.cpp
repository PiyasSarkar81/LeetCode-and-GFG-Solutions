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
    void swapNode(TreeNode* node){
        if(!node) return;
        
        swapNode(node->left);
        swapNode(node->right);
        
        TreeNode* temp = node->right;
        node->right = node->left;
        node->left = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        swapNode(root);
        return root;
    }
};