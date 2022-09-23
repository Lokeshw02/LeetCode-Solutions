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
    
    int helper(TreeNode* root, unordered_map<TreeNode*, int>&dp ){
        
        if(!root) return 0 ;
        
        if(dp.find(root) != dp.end()) 
            return dp[root] ;
        
        int left = helper(root->left,dp) ;
        int right = helper(root->right,dp) ;
        
        int ans = root->val ;
        
        if(root->left){
            ans+= helper(root->left->left,dp) ;
            ans += helper(root->left->right,dp) ; 
        }
        
        if(root->right){
            ans += helper(root->right->left,dp) ;
            ans += helper(root->right->right,dp) ;
        }
        
        dp[root] = max(ans, left + right ) ;
        return dp[root] ;
     }
    
    
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int>dp ;
        
        return helper(root,dp) ;
    }
};