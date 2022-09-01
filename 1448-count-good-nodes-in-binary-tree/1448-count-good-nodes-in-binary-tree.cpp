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
    
    
    int search(TreeNode* root, int max ){
        
        if(!root) return 0 ;
        int count = 0 ;
        if(root->val >= max){
            max = root->val ; 
            count++ ;
        }
        
        count += search(root->left, max) ;
        count += search(root->right, max) ;
        
            
        return count ;
    
    }
    
    
    
    int goodNodes(TreeNode* root) {
        
        
        if(!root) return 0 ;
        
        if(root->left == NULL && root->right == NULL) return 1 ;
        
        int good = 1 ; //Root is always a good Node 
        
        good += search(root->left,root->val) ;
        good += search(root->right,root->val) ; 
        
        return good ;
    }
};