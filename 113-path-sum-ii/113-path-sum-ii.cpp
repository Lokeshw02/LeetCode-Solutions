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
    vector<vector<int>> v;
    vector<int> temp;
    int sum=0;
    
    void helper(TreeNode *root,int sum, int targetSum,vector<int> temp){
        if(root==NULL){
            return ;
        }
        
        sum+=root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right){
            if(sum==targetSum){
                v.push_back(temp);
            }
            else{
                return;
            }
        }
        
        helper(root->left,sum,targetSum,temp);
        helper(root->right,sum,targetSum,temp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root,0,targetSum,temp);
        return v;
        
    }
};
