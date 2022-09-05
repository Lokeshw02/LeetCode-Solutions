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
    
    map<int,map<int,multiset<int>>> m ;
    
    void dfs(TreeNode* root, int col , int row){
        
        if(!root) return ;
        
        m[col][row].insert(root->val) ;
        
        
        //Left 
        dfs(root->left,col-1,row+1) ;
        //Right 
        dfs(root->right,col+1,row+1) ;
    }
    
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs(root,0,0) ;
        vector<vector<int>>res ;
        
        for(auto t1 : m){
            res.push_back(vector<int>()) ;
            for(auto t2 : t1.second )
            {
                for(auto t3 : t2.second)
                    res.back().push_back(t3) ;
            }
        }
        
        
        return res ;
        
    }
};