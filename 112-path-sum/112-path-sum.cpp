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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //Base condition 
        
        if(root == NULL) return false ;
        
        //True Condition --> Leaf Node and Sum Becomes 0 
        
        if(root->left ==NULL && root->right ==  NULL && targetSum-root->val ==0) return true ;
        
        //Chek if the value exists in the left and right Subtree 
        
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val) ;
    }
};