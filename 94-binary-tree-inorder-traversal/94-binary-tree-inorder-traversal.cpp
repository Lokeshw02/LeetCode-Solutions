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
    
    
    void  inorder(TreeNode* root, vector<int>& res){
        
        //Base Case 
        
        if(root == NULL) return ;
        
        //Visit Left Subtree 
        inorder(root->left, res) ;
        //Visit node 
        res.push_back(root->val) ;
        //Visit Right Subtree 
        inorder(root->right,res ) ;
        
        
        
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        
     vector<int> res ;
     inorder(root,res) ;
        return res ;
        
    }
    
    
};