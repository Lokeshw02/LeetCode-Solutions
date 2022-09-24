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
    
    void helper(TreeNode* root, int targetSum, vector<int>&curr, vector<vector<int>>&res){
        
        
        if(!root) return ;
        
         curr.push_back(root->val) ; 
        
        targetSum -= root->val ;
        
        if(root->left == NULL && root->right == NULL ){
            
            if(targetSum == 0)
            res.push_back(curr) ;
        
        }
        
      
        
        helper(root->left,targetSum , curr, res) ; 
        
        helper(root->right,targetSum, curr, res) ;
        
        curr.pop_back() ;
        
    }
   
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res ;
        vector<int> curr ;
        
        helper(root, targetSum, curr, res) ;
        
        return res ;
    }
};