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
    
    void postorder(TreeNode* root,vector<int>&res){
        
        //Base Condition 
        if(root==NULL) return ;
        
        //Visit Left Subtree
        postorder(root->left,res) ;
        
        //Visit Right Subtree 
        postorder(root->right,res) ;
        
        //Visit Node 
        res.push_back(root->val) ;
        
        
    }
    
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res ;
        postorder(root,res) ;
        
        return res ;
    }
};