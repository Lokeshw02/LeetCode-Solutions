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
    
    int solve(TreeNode* root, int &res){
        if(root  == NULL) 
            return 0 ;
        
        int l = solve(root->left, res) ;
        int r = solve(root->right, res) ;
        
        int height = max(l,r) +1 ;
        int ans = max(height, l+r+1) ;
        res = max(res,ans) ;
        
        return height ;
     }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN ;
        
        solve(root, res) ;
        
        
        return res -1;
    }
};