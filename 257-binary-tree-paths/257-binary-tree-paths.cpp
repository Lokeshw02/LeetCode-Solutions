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
    
     vector<string> ans;
    
    void helper(TreeNode* root, string temp){
        if(root && !root->left && !root->right){
            temp+=to_string(root->val);
            ans.push_back(temp);
            return;
        }
        
        if(!root) return;
        
        temp=temp+to_string(root->val)+"->";
        
        helper(root->left, temp);
        
        helper(root->right, temp);
    }
    
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string temp="";
        helper(root, temp);
        return ans;
    }
};