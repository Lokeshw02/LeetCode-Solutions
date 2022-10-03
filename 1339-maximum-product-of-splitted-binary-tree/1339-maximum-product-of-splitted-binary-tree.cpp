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
    
    long long  helper(TreeNode* root, long long &total , long long &res ){
        
        if(!root) return 0 ;
        
        long long  l =  helper(root->left, total , res) ; 
        
         res =  max( res, l*(total-l) ) ;
        
        long long r =  helper(root->right, total , res) ; 
        
        res = max(res, r*(total -r)) ;
        
        return root->val + l + r ;
        
        
    }
    
    int getsum(TreeNode* root){
        
        if(!root) return 0  ;
        
        return root->val + getsum(root->left) + getsum(root->right) ;
    }
    
    
    
    int maxProduct(TreeNode* root) {
        long long res = 0 ; 
        long long sum = getsum(root) ;
        
        long long total = helper(root,sum,res) ;
        
        return res%1000000007 ;
      
        
        
        
        
        
        
    }
};