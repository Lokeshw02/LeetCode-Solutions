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
    
    
    void Preorder(TreeNode* root, vector<int>&res){
        //Base condition 
        if(root == NULL) return ;
        //Visit Node 
        res.push_back(root->val) ;
        //Visit Left Subtree
        Preorder(root->left,res) ;
        //Visit Right Subtree 
        Preorder(root->right,res) ;
    }
    
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res ;
        Preorder(root,res) ;
        
        return res  ;
    }
};