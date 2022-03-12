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
    TreeNode* invertTree(TreeNode* root) {
        
        //Base Case - If we reach NUll 
        if(root == NULL ) return NULL ;
        //if only one child is there 
        if(root->left == NULL && root->right == NULL) return root ;
        
        //Connect left side to the right side 
        TreeNode* leftChild = root->left ;
        
        root->left = root->right ;
        
        //Connect right to the left side 
        root->right = leftChild ;
        
        //Call Recusively for left SUbtree 
        invertTree(root->left) ;
        
        //Call recursively for the RIght Subtree 
        
        invertTree(root->right) ;
        
        
        return root ;
    }
};