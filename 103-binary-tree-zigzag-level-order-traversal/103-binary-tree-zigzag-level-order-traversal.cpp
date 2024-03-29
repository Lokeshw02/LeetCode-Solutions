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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
       vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root)
            return ans;
        
        q.push(root);
        
        bool isRev= false;
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++)
            {
                TreeNode *node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            
            if(isRev){
                reverse(temp.begin(),temp.end());
               // isRev = false;
            }
            ans.push_back(temp);
            isRev = !isRev ;
        }
        
        return ans;
    }
};