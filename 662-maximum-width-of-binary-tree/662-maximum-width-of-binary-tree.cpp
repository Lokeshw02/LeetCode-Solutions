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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0 ;
        
        queue<pair<TreeNode*, int>> q ; 
        
        q.push({root,0}) ;
        
         int ans = INT_MIN ;
        
        while(!q.empty()){
        int n = q.size() ;
        
        int min_idx = q.front().second ;
        int first_idx,last_idx ;
       
        
        
        for(int i = 0 ; i < n ; i++){
            long long curr_idx = q.front().second - min_idx ;
            
            if(i == 0) 
                first_idx = curr_idx ;
            if(i == n-1) 
                last_idx = curr_idx ;
            
            TreeNode* t = q.front().first ;
            
            q.pop() ;
            
            if(t->left) 
                q.push({t->left,2*curr_idx+1}) ;
            
            if(t->right) 
                q.push({t->right,2*curr_idx +2}) ;
            
            
        }
         ans = max(ans , last_idx-first_idx+1) ;
        
       
        
    }
      return ans ; 
    }
};