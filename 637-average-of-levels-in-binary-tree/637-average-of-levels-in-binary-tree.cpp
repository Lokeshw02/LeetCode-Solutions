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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> res ;
        
        queue<TreeNode*> q ;
        
         q.push(root) ;
       // res.push_back(root->val) ;
        
        while(!q.empty()){
            double size = q.size() ;
            double sum = 0 ;
            
            
            for(int i = 0; i < size ; i++){
                
                
            TreeNode* t = q.front() ; 
            
            sum += t->val ;
           
            q.pop() ;
                
            if(t->right != NULL)
            q.push(t->right); 
            if(t->left != NULL)
            q.push(t->left) ;
                
            }
            
            
           
            
            
          res.push_back(sum/size) ;  
        }
        
        return res ;
    }
};