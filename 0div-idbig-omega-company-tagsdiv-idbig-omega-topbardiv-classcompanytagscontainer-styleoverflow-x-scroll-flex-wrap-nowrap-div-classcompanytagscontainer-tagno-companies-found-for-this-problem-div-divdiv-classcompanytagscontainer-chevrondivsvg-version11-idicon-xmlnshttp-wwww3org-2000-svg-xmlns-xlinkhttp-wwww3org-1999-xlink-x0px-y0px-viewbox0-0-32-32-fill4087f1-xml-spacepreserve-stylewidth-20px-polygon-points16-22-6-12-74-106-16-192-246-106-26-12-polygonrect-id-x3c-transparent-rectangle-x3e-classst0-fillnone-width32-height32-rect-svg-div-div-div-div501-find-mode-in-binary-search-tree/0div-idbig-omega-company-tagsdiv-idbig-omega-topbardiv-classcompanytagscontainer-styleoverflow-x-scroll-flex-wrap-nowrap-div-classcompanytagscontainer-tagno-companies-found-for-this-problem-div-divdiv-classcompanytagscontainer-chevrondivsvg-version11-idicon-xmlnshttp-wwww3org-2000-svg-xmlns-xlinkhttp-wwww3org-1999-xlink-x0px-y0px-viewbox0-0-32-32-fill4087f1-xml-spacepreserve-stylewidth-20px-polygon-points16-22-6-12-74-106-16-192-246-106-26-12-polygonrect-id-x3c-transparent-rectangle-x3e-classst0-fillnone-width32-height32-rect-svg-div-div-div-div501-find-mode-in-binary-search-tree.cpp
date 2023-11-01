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

    void solve(TreeNode* node,unordered_map<int,int>& mp){
        if(node == NULL) return;
        mp[node->val]++;
        solve(node->left,mp);
        solve(node->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        solve(root,mp);
        vector<int> ans;
        int maxFreq = 0;
        for(auto m : mp){
            if(m.second == maxFreq) ans.push_back(m.first);
            else if(m.second > maxFreq){
                maxFreq = m.second;
                ans = {m.first};
            }
        }
        return ans;
    }
};