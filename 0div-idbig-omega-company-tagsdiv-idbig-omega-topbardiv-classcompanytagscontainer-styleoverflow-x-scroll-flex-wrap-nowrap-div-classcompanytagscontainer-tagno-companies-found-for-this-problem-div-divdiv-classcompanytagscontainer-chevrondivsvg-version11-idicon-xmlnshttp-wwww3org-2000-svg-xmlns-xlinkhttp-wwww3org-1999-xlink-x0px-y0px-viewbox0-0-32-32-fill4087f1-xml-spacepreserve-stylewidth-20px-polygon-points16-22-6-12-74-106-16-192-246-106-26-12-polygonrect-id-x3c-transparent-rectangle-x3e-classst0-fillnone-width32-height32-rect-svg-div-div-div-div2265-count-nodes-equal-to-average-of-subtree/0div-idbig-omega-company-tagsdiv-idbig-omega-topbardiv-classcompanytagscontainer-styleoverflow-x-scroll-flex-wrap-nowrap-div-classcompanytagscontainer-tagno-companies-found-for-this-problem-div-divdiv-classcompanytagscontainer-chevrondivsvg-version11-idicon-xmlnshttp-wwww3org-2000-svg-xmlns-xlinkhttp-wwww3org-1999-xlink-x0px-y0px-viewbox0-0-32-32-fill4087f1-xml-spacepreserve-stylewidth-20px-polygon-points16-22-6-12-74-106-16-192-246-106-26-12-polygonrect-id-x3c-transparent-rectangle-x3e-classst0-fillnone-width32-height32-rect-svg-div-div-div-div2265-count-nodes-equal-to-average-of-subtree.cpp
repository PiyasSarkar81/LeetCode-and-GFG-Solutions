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
    pair<int,int> f(TreeNode* node, int &ans){
        if(!node) return {0,0};
        auto p1 = f(node->left,ans);
        auto p2 = f(node->right,ans);
        int avg = (node->val+p1.first+p2.first)/(p1.second+p2.second+1);
        if(avg == node->val)ans++;
        return {node->val+p1.first+p2.first,p1.second+p2.second+1}; 
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        f(root,ans);
        return ans;
    }
};