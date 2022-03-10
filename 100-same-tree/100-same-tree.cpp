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
    
    bool checkSame(TreeNode* p, TreeNode* q){
     
    //If both are NULL -> return true ;
    if(p== NULL && q == NULL) return true ;
    //If one of the roots is NULL and other is not  ; return false ;
    if(p == NULL || q == NULL) return false ;
    //Cheking for the values 
    if(p->val != q->val ) return false ;
        
    //Call Recursively for the left and right subtree 
    
    return checkSame(p->left,q->left) && checkSame(p->right,q->right) ;
        
    }
        
        
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return checkSame(p,q) ;
    }
};