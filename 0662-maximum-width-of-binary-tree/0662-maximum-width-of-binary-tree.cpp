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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans =0;
        while(!q.empty()){
            int base = q.front().second;
            int size = q.size();
            int first,last;
            for(int i=0;i<size;i++){
                int curr_index = q.front().second - base;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curr_index;
                if(i==size-1) last = curr_index;
                if(node->left) q.push({node->left,(long long)curr_index*2+1});
                if(node->right) q.push({node->right,(long long)curr_index*2+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};