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
    TreeNode* Tree(vector<int>& in,int a, int b, vector<int>& po,int x,int y){
        if(a>b || x>y) return nullptr;
        TreeNode *node = new TreeNode(po[y]);
        int r = a;
        while(node->val != in[r])r++;
        node -> left = Tree(in,a,r-1,po,x,x+r-a-1);
        node -> right = Tree(in,r+1,b,po,x+r-a,y-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Tree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};