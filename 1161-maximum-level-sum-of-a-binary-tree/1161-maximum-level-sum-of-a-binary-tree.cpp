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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = 0, level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            level++;
            int currSum = 0;
            
            // itrate all the nodesat current level
            for(int sz = q.size(); sz>0; sz--){
                TreeNode* node = q.front();
                q.pop();
                currSum += node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            if(maxSum < currSum) {
                maxSum = currSum;
                ans = level;
            }
        }
        return ans;
    }
};